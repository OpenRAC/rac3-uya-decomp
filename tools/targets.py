"""The executables this repo decompiles, and where each one's files live.

Every tool works on one target at a time. The target comes from, in order:
  * a `--target NAME` option (tools strip it from sys.argv with from_argv());
  * the UYA_TARGET environment variable;
  * frontbin, the default, so existing commands behave exactly as before.

A target has one source-file list and one flags file (text_parts) covering all
of its code. Its code can sit in several sections ("units"): boot_elf has the
engine core (core.text) and the front-end overlay (.text). A unit is an address
range; each unit's files build into one object, and each unit gets its own
place in the linker script. Address ranges of different units never overlap,
so every by-address lookup (file_for_address, flags_for) works on the whole
target.

Function names are func_<address>, so two targets can both have a
func_00381180 that are unrelated functions. Anything keyed by function name
(divs_nops, sq_ra_funcs, localdecomp_flags, symbol files) is per target.
"""
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class Unit:
    def __init__(self, name, start, end, src_dir, asm_dir, section, objdir=None):
        self.name = name          # "text", "core"
        self.objdir = objdir or name  # folder under <build>/src/ for its per-file objects
        self.start = start        # first address of the code section
        self.end = end            # one past its last byte
        self.src_dir = src_dir    # where its .c files live (relative to ROOT)
        self.asm_dir = asm_dir    # INCLUDE_ASM folder for its functions
        self.section = section    # section name in the ELF (".text", "core.text")

    def contains(self, addr):
        return self.start <= addr < self.end


class Target:
    def __init__(self, name, **kw):
        self.name = name
        self.__dict__.update(kw)

    def path(self, attr):
        return os.path.join(ROOT, getattr(self, attr))

    def unit_for(self, addr):
        for u in self.units:
            if u.contains(addr):
                return u
        return None

    def unit(self, name):
        for u in self.units:
            if u.name == name:
                return u
        raise KeyError(f"{self.name} has no unit {name!r} (units: {', '.join(u.name for u in self.units)})")

    def obj(self, unit):
        """The relocatable object build_text.py links one unit's files into."""
        return os.path.join(self.build_dir, "src", unit.name + ".c.o")

    def workdir(self, unit):
        """Where build_text.py puts one unit's per-file objects (objdiff reads them)."""
        return os.path.join(self.build_dir, "src", unit.objdir)

    def objdiff_prefix(self, unit):
        return self.objdiff_units[unit.name]

    def objdiff_dir(self, unit):
        """Folder under build/objdiff/{target,base}/ for one unit's per-file objects."""
        return self.objdiff_dirs[unit.name]


TARGETS = {
    # frontbin keeps the paths it has always had.
    "frontbin": Target(
        "frontbin",
        elf="frontbin.elf",
        sha1="3bc94ee895e4b4af9b5602a229af599c1103b542",
        yaml="frontbin.splat.yaml",
        ld="linker_scripts/frontbin.ld",
        build_dir="build",
        bin_name="frontbin.bin",
        files="tools/src_files.txt",
        parts="tools/text_parts.txt",
        divs_nops="tools/divs_nops.txt",
        sq_ra_funcs="tools/sq_ra_funcs.txt",
        localdecomp_flags="tools/localdecomp_flags.txt",
        symbol_addrs="symbol_addrs.txt",
        symbols_resolved="symbol_addrs_resolved.txt",
        asm_root="asm",
        handwritten="asm/handwritten",
        remnants="asm/remnants",
        gp=0x1DC8B0,
        units=[Unit("text", 0x37D100, 0x3ECFA4, "src/frontbin", "asm/nonmatchings/text", ".text", objdir="frontbin")],
        # objdiff: unit name prefix, object folder under build/objdiff/{target,base}/
        # and progress categories, per code section (tools/gen_objdiff_units.py)
        objdiff_units={"text": "frontbin/src/"},
        objdiff_dirs={"text": "frontbin"},
        objdiff_categories={"text": ["frontend"]},
        # raw byte ranges of the file that aren't code or data: (asm name, start, end)
        raw_blobs=[("header", 0x0, 0x1000)],
        splat_src="src",
        # data segments holding switch jump tables: {segment: unit that uses them}
        jtbl_segments={"data": "text"},
        label="frontbin (front end)",
    ),
    # boot_elf.elf: the engine core (core.text) plus a front-end overlay
    # (.text) that is frontbin's code linked at other addresses.
    "boot_elf": Target(
        "boot_elf",
        elf="boot_elf.elf",
        sha1="487975305f8a263c750dfede50391b575ed07835",
        yaml="boot_elf.splat.yaml",
        ld="linker_scripts/boot_elf.ld",
        build_dir="build/boot_elf",
        bin_name="boot_elf.bin",
        files="targets/boot_elf/src_files.txt",
        parts="targets/boot_elf/text_parts.txt",
        divs_nops="targets/boot_elf/divs_nops.txt",
        sq_ra_funcs="targets/boot_elf/sq_ra_funcs.txt",
        localdecomp_flags="targets/boot_elf/localdecomp_flags.txt",
        symbol_addrs="targets/boot_elf/symbol_addrs.txt",
        symbols_resolved="targets/boot_elf/symbol_addrs_resolved.txt",
        asm_root="asm/boot_elf",
        handwritten="asm/boot_elf/handwritten",
        remnants="asm/boot_elf/remnants",
        gp=0x1DC8B0,
        units=[
            Unit("core", 0x116F80, 0x13D420, "src/boot_elf/core", "asm/boot_elf/nonmatchings/core", "core.text"),
            Unit("text", 0x381180, 0x3F25B8, "src/boot_elf/text", "asm/boot_elf/nonmatchings/text", ".text"),
        ],
        objdiff_units={"core": "boot_elf/core/", "text": "boot_elf/text/"},
        objdiff_dirs={"core": "boot_elf/core", "text": "boot_elf/text"},
        objdiff_categories={"core": ["executables", "boot_elf", "boot_elf_core"],
                            "text": ["executables", "boot_elf", "boot_elf_frontend"]},
        # objdiff.json units this target's per-file units replace (the old
        # reference-only unit for the whole code)
        objdiff_replaces=["exes/boot_elf"],
        # 0x0..0x2000: ELF header, program headers and .reginfo; 0x35EA98..: .shstrtab
        # and the section header table
        raw_blobs=[("header", 0x0, 0x2000), ("trailer", 0x35EA98, 0x35EE64)],
        splat_src="src/boot_elf",
        # core.rdata isn't split: its jump tables sit between each source file's
        # other read-only data (strings, constants), so splitting it means giving
        # every piece to its file. Needed once a core switch function becomes C.
        jtbl_segments={"data": "text"},
        label="boot_elf (engine core + boot front end)",
    ),
}

DEFAULT = "frontbin"


def get(name=None):
    name = name or os.environ.get("UYA_TARGET") or DEFAULT
    if name not in TARGETS:
        sys.exit(f"unknown target {name!r}; known: {', '.join(TARGETS)}")
    return TARGETS[name]


def from_argv(argv=None):
    """Take `--target NAME` / `--target=NAME` out of argv (sys.argv by default),
    set UYA_TARGET for any tool this one runs, and return the Target."""
    argv = sys.argv if argv is None else argv
    name = None
    i = 1
    while i < len(argv):
        a = argv[i]
        if a == "--target" and i + 1 < len(argv):
            name = argv[i + 1]
            del argv[i:i + 2]
            continue
        if a.startswith("--target="):
            name = a.split("=", 1)[1]
            del argv[i]
            continue
        i += 1
    t = get(name)
    os.environ["UYA_TARGET"] = t.name
    return t


def for_function_address(addr):
    """Every target whose code contains `addr` (names are only unique per target)."""
    return [t for t in TARGETS.values() if t.unit_for(addr)]
