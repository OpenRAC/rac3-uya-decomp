#!/usr/bin/env python3
"""permuter_scorer.py: score a permuter candidate by aligned instruction diffs.

decomp-permuter's own scorer compares objdump text with per-category weights.
For this project its score often disagrees with what actually separates a
near miss from a match (one function scored 180 at 5 real diffs, another 3010
at 2), so the permuter wanders. This module scores the way the matching agents
measure functions: the candidate's instructions and retail's are aligned with
difflib (relocated fields resolved, branch targets compared through the
alignment), and the score is the number of instructions that differ. 0 means
byte-identical apart from relocations, which tools/try_func.py then confirms.

Use it through decomp-permuter with the small hook in
tools/decomp-permuter-aligned-scorer.patch (apply it once in your
decomp-permuter checkout), then:

    export PERMUTER_ALIGNED_SCORER=$PWD/tools/permuter_scorer.py
    export PERMUTER_ALIGNED_FUNC=func_003B7B50
    export UYA_TARGET=frontbin           # or boot_elf / i5bootn
    python3 ../decomp-permuter/permuter.py nonmatchings/func_003B7B50 -j2 --stop-on-zero

The permuter's own score is replaced by 10 * aligned diffs. Without the two
PERMUTER_ALIGNED_* variables the patched permuter behaves as before.

Command line, for checking a single object:

    python3 tools/permuter_scorer.py candidate.o func_003B7B50
"""
import difflib, os, re, struct, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

_cwd = os.getcwd()
os.chdir(ROOT)
import targets  # noqa: E402
import try_func as tf  # noqa: E402
os.chdir(_cwd)
from elftools.elf.elffile import ELFFile  # noqa: E402

_retail = None
_cache = {}
BRANCH_OPS = (4, 5, 6, 7, 20, 21, 22, 23)
REGIMM_BRANCHES = (0, 1, 2, 3, 16, 17, 18, 19)


def _norm(w):
    s = re.sub(r"\s+", " ", tf.dis(w))
    m = re.match(r"(b\w*|j) (.*?)(0x[0-9a-f]+)$", s)
    if m and (s.startswith("b") or s.startswith("j ")):
        s = m.group(1) + " " + m.group(2) + "@"   # branch targets are compared separately
    return s


def _words(b):
    return [struct.unpack("<I", b[i:i + 4])[0] for i in range(0, len(b) - 3, 4)]


def _target(w, i):
    op = w >> 26
    if op in BRANCH_OPS or (op == 1 and ((w >> 16) & 0x1F) in REGIMM_BRANCHES):
        o = w & 0xFFFF
        o = o - 0x10000 if o & 0x8000 else o
        return i + 1 + o
    return None


def _retail_words(func, size):
    global _retail
    if func not in _cache:
        if _retail is None:
            _retail = tf.Retail(os.path.join(ROOT, targets.get().elf))
        th = _words(_retail.read(int(func[5:13], 16), tf.retail_size(func, size)))
        B = [_norm(w) for w in th]
        # jump-table address halves (lui 0x32 / addiu same reg) are relocations
        jr = set()
        for j in range(len(th)):
            if B[j].startswith("lui") and B[j].endswith(", 0x32"):
                B[j] = re.sub(r"0x32$", "M", B[j])
                jr.add(B[j].split()[1].rstrip(","))
            elif B[j].startswith("addiu") and jr:
                m = re.match(r"addiu (\$\w+), (\$\w+), (-?0x[0-9a-f]+)$", B[j])
                if m and m.group(2) in jr and m.group(1) == m.group(2):
                    B[j] = f"addiu {m.group(1)}, {m.group(2)}, M"
                    jr.discard(m.group(2))
        _cache[func] = (th, B)
    return _cache[func]


def score(o_path, func):
    """Aligned diff count of FUNC in object O_PATH against retail."""
    o_path = os.path.abspath(o_path)
    cwd = os.getcwd()
    os.chdir(ROOT)
    try:
        elf = ELFFile(open(o_path, "rb"))
        text = elf.get_section_by_name(".text").data()
        resolved, mask = tf.resolve_relocations(elf, text)
        sym = [s for s in elf.get_section_by_name(".symtab").iter_symbols() if s.name == func][0]
        off, size = sym["st_value"], sym["st_size"]
        th, B = _retail_words(func, size)
        ours = _words(text[off:off + size])
        for i in range(len(ours)):
            if off + i * 4 in resolved:
                ours[i] = resolved[off + i * 4]
        A = [_norm(w) for w in ours]
        for i in range(len(ours)):
            if (off + i * 4) in mask and mask[off + i * 4] != 0xFFFFFFFF:
                A[i] = re.sub(r"(-?0x[0-9a-f]+|\b\d+)$", "M", A[i])
        sm = difflib.SequenceMatcher(None, A, B, autojunk=False)
        mapping = {}
        ops = sm.get_opcodes()
        for tag, i1, i2, j1, j2 in ops:
            if tag == "equal":
                for k in range(i2 - i1):
                    mapping[i1 + k] = j1 + k
        nd = 0
        for tag, i1, i2, j1, j2 in ops:
            if tag == "equal":
                for k in range(i2 - i1):
                    ti, tj = _target(ours[i1 + k], i1 + k), _target(th[j1 + k], j1 + k)
                    if ti is not None and mapping.get(ti) != tj:
                        nd += 1
                continue
            nd += max(i2 - i1, j2 - j1)
        return nd
    finally:
        os.chdir(cwd)


if __name__ == "__main__":
    targets.from_argv()
    print(score(sys.argv[1], sys.argv[2]))
