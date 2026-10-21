"""Compile common-level C, prove its retail bytes, and build a partial objdiff base.

Requires personal level ELFs, the original 51 level target objects, and their
split common.o. Never uses retail instructions to fill missing base functions.
"""
import argparse
import hashlib
import io
import json
import os
import re
from pathlib import Path
from types import SimpleNamespace

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

import sys

# A common-level function is proven with the default target's tools and the
# common-level tables (config/levels/), as CI's levels/common base is. A
# UYA_TARGET left set in the caller's environment (UYA_TARGET=veldin, say)
# would make asm_filter read that target's divs_nops/sq_ra tables too, so a
# source could pass here and fail in CI. try_level.py, seed_levels.py and
# anything else that proves functions through this module gets the same rule.
os.environ.pop("UYA_TARGET", None)

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "objdiff"))  # split_shared_levels.py
import pr_check  # noqa: E402
import split_shared_levels as shared  # noqa: E402
import check as matching


ROOT = Path(__file__).resolve().parent.parent


def require(condition, message):
    if not condition:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def text_function(elf, symbol):
    section_index = symbol["st_shndx"]
    return symbol["st_info"]["type"] == "STT_FUNC" and isinstance(section_index, int) and elf.get_section(section_index).name == ".text"


def allocated_payload(section):
    if not section["sh_size"] or not section["sh_flags"] & shared.SHF_ALLOC or section.name == ".text":
        return False
    metadata = {".reginfo": "SHT_MIPS_REGINFO", ".MIPS.abiflags": "SHT_MIPS_ABIFLAGS"}
    return not (section.name in metadata and section["sh_type"] == metadata[section.name] and section["sh_size"] == 24)


def inventory(targets):
    paths = sorted(targets.glob("*.o"), key=lambda path: shared.level_no(str(path)))
    require(len(paths) == 51, "expected the 51 original, unsplit level target objects")
    levels = [shared.Level(str(path)) for path in paths]
    require(len({level.no for level in levels}) == 51, "duplicate level numbers")
    owners, occurrences = {}, {}
    for level in levels:
        hashes = set()
        for _, name, offset, size, identity in level.funcs:
            owners.setdefault(identity, (level, name, offset, size))
            hashes.add(identity)
        for identity in hashes:
            occurrences[identity] = occurrences.get(identity, 0) + 1
    return {identity: owner for identity, owner in owners.items() if occurrences[identity] > 1}


def uses_inline_asm(source_bytes):
    """True if a common-level source uses GCC inline assembly statements (VU0
    macro mode, MMI), which count as C, as they did in the original; ValueError
    for every other kind of assembly (pr_check.inline_asm_statements)."""
    try:
        return bool(pr_check.inline_asm_statements(source_bytes.decode("utf-8")))
    except ValueError as error:
        raise ValueError("assembly source cannot receive C credit: %s" % error) from None


def compile_entry(entry, levels_dir, targets_dir, owners, common, options):
    name = entry["name"]
    require(name.startswith("func_") and int(name[5:], 16) == int(entry["address"], 16), "name/address mismatch")
    size = int(entry["size"])
    require(size > 0 and size % 4 == 0, "invalid function size")
    source = (ROOT / entry["source"]).resolve()
    require(source.is_relative_to(ROOT) and source.suffix == ".c", "source must be a C file in the repository")
    source_bytes = source.read_bytes()
    code = pr_check.strip_comments(source_bytes.decode("utf-8"))
    require({match.group(1) for match in pr_check.DEF_RE.finditer(code)} == {name}, "source must define only the catalogued function")
    inline_asm = uses_inline_asm(source_bytes)
    require(bool(entry.get("inline_asm", False)) == inline_asm,
            "catalogue field inline_asm must be %s: the source %s inline assembly" % (str(inline_asm).lower(), "uses" if inline_asm else "has no"))
    overlay_path = (levels_dir / entry["overlay"] / "overlay.elf").resolve()
    require(overlay_path.is_relative_to(levels_dir.resolve()), "overlay escapes the supplied level directory")
    member_path = targets_dir / (Path(entry["overlay"]).name + ".o")
    with overlay_path.open("rb") as stream:
        retail = ELFFile(stream)
        section = retail.get_section_by_name(".text")
        require(section is not None and retail.little_endian, "expected little-endian retail .text")
        offset = int(entry["address"], 16) - section["sh_addr"]
        require(0 <= offset <= section["sh_size"] - size, "function outside retail .text")
        retail_bytes = section.data()[offset:offset + size]
    with member_path.open("rb") as stream:
        member_bytes_full = stream.read()
        member = ELFFile(io.BytesIO(member_bytes_full))
        symbols = member.get_section_by_name(".symtab")
        matches = [symbol for symbol in symbols.iter_symbols() if symbol.name == name]
        require(len(matches) == 1, "ambiguous or missing original target symbol")
        target = matches[0]
        require(text_function(member, target) and target["st_value"] == offset and target["st_size"] == size, "target does not confirm the complete function boundary")
        member_bytes = member.get_section_by_name(".text").data()[offset:offset + size]
    identity = shared.norm_hash(member_bytes)
    require(identity in owners, "function is not shared by multiple levels")
    owner, owner_name, owner_offset, owner_size = owners[identity]
    require(Path(owner.path).name == member_path.name and owner_name == name and owner_offset == offset and owner_size == size, "catalogue does not select the canonical common owner")
    require(name in common and common[name] == member_bytes, "split common target differs from its canonical owner")
    donor_address = int(entry["flags_from"][5:], 16)
    flags = matching.apply_overrides(matching.flags_for(donor_address), entry["mode"], entry["assembler"])
    object_path = matching.compile_c(str(source), flags, options, name)
    require(object_path is not None, "C compilation failed")
    with open(object_path, "rb") as stream:
        compiled = ELFFile(stream)
        require(compiled.little_endian, "compiler object is not little-endian")
        symbols = compiled.get_section_by_name(".symtab")
        matches = [symbol for symbol in symbols.iter_symbols() if symbol.name == name]
        require(len(matches) == 1 and matches[0]["st_size"] == size and text_function(compiled, matches[0]), "compiled size, section or symbol differs")
        start = matches[0]["st_value"]
        text = compiled.get_section_by_name(".text").data()
        raw = text[start:start + size]
        require(len(raw) == size, "truncated compiler body")
        resolved, masks = matching.resolve_relocations(compiled, text)
        require(not any(start <= position < start + size for position in masks), "unresolved/masked relocation")
        linked = bytearray(raw)
        for position, word in resolved.items():
            if start <= position < start + size:
                linked[position - start:position - start + 4] = word.to_bytes(4, "little")
        require(bytes(linked) == retail_bytes, "fully resolved C bytes differ from retail")
        require(raw == member_bytes, "compiler object encoding differs from the common target; no projection is permitted")
        require(not any(allocated_payload(section) for section in compiled.iter_sections()), "unexpected allocated compiler section")
        relocations = []
        for section in compiled.iter_sections():
            if isinstance(section, RelocationSection) and section.name in (".rel.text", ".rela.text"):
                for relocation in section.iter_relocations():
                    position = relocation["r_offset"]
                    if start <= position < start + size:
                        symbol = symbols.get_symbol(relocation["r_info_sym"])
                        relocations.append({"offset": position - start, "type": relocation["r_info_type"], "symbol": symbol.name, "address": matching.symbol_address(symbol.name)})
    proof = {
        "name": name, "source": entry["source"], "overlay": entry["overlay"],
        "address": entry["address"], "size": size, "flags": flags,
        "source_sha256": digest(source_bytes), "retail_sha256": digest(overlay_path.read_bytes()),
        "owner_object_sha256": digest(member_bytes_full),
        "resolved_body_sha256": digest(linked), "object_body_sha256": digest(raw),
        "strict_equal": True, "masked_words": 0, "canonical_owner": True, "inline_asm": inline_asm,
        "relocations": relocations,
    }
    return raw, proof


_WORKER = None


def _init_worker(state):
    global _WORKER
    _WORKER = state


def _prove(entry):
    levels_dir, targets_dir, owners, common, options = _WORKER
    try:
        return compile_entry(entry, levels_dir, targets_dir, owners, common, options), None
    except (ValueError, OSError, KeyError) as error:
        return None, str(error)


def prove_all(catalogue, args, owners, common, options):
    """(entry, raw, proof) for every catalogue entry, in catalogue order. The
    gates are compile_entry's either way; with --jobs > 1 the entries are
    proven in parallel processes, and the first failure still fails the build."""
    if args.jobs <= 1:
        for entry in catalogue:
            yield (entry,) + compile_entry(entry, args.levels_dir, args.targets_dir, owners, common, options)
        return
    import concurrent.futures
    # compile_entry reads only each owner level's .path, so the workers get
    # that instead of the 51 parsed level objects
    light = {identity: (SimpleNamespace(path=level.path), name, offset, size)
             for identity, (level, name, offset, size) in owners.items()}
    state = (args.levels_dir, args.targets_dir, light, common, options)
    with concurrent.futures.ProcessPoolExecutor(args.jobs, initializer=_init_worker, initargs=(state,)) as pool:
        for entry, (result, error) in zip(catalogue, pool.map(_prove, catalogue, chunksize=8)):
            require(error is None, f"{entry['name']}: {error}")
            yield (entry,) + result


def target_proven(owners, common, skip):
    """Shared functions that a level target's own files have as C.

    Some shared functions only match in their owner level's full build: a
    pair that reads a variable defined in their source file, say (the
    variable can't live in two one-function sources). That build proves them
    byte for byte. They count here when the owner level is a target with a
    built object for the file, the function is that level's canonical owner,
    and its compiled body equals the split common target's (gate 5)."""
    import targets
    import srcfiles as sf
    by_name = {}
    for level, name, offset, size in owners.values():
        by_name.setdefault(name, []).append(Path(level.path).stem)
    found, skipped = [], []
    for t in targets.TARGETS.values():
        overlay = getattr(t, "level_overlay", None)
        if not overlay:
            continue
        level = Path(overlay).name
        unit = t.units[0]
        for rel, _ in sf.read_file_list(t.path("files")):
            if sf.standalone(rel):
                continue
            text = sf.read_source(rel)
            for m in re.finditer(r"/\* localdecomp:start (func_[0-9A-Fa-f]{8}) \*/(.*?)/\* localdecomp:end \1 \*/", text, re.S):
                name = m.group(1)
                if name in skip or level not in by_name.get(name, []) or name not in common:
                    continue
                obj = Path(t.workdir(unit)) / (Path(rel).stem + ".o")
                if not obj.exists():
                    skipped.append(f"{name}: {obj} not built (make check-{t.name})")
                    continue
                with obj.open("rb") as stream:
                    elf = ELFFile(io.BytesIO(stream.read()))
                    sym = [s for s in elf.get_section_by_name(".symtab").iter_symbols() if s.name == name]
                    if len(sym) != 1 or not text_function(elf, sym[0]):
                        skipped.append(f"{name}: not one .text function in {obj.name}")
                        continue
                    data = elf.get_section(sym[0]["st_shndx"]).data()
                    raw = data[sym[0]["st_value"]:sym[0]["st_value"] + sym[0]["st_size"]]
                if raw != common[name]:
                    skipped.append(f"{name}: {t.name} build's body differs from the split common target")
                    continue
                block = pr_check.strip_comments(m.group(2))
                proof = {"name": name, "source": rel, "via_target": t.name, "size": len(raw),
                         "inline_asm": bool(re.search(r"\b(?:__asm__|asm)\b", block)),
                         "object_body_sha256": digest(raw), "strict_equal": True, "canonical_owner": True}
                found.append((name, raw, proof))
    return found, skipped


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--levels-dir", required=True, type=Path)
    parser.add_argument("--targets-dir", required=True, type=Path)
    parser.add_argument("--common-target", required=True, type=Path)
    parser.add_argument("--catalogue", type=Path, default=ROOT / "config/levels/common_c.json")
    parser.add_argument("--output", type=Path, default=ROOT / "build/objdiff/base/common.o")
    parser.add_argument("--toolchain", default=matching.DEFAULT_TOOLCHAIN)
    parser.add_argument("--runner")
    parser.add_argument("--jobs", type=int, default=os.cpu_count() or 1,
                        help="prove functions in this many processes (default: one per CPU; 1 = in this process)")
    args = parser.parse_args()
    output = args.output.resolve()
    require(not output.is_relative_to(ROOT) or output.is_relative_to(ROOT / "build"), "write generated outputs in build/ or outside the repository")
    catalogue = json.loads(args.catalogue.read_text(encoding="utf-8"))
    require(bool(catalogue), "empty common C catalogue")
    require(len({entry["name"] for entry in catalogue}) == len(catalogue), "duplicate catalogued function")
    owners = inventory(args.targets_dir)
    common_bytes_full = args.common_target.read_bytes()
    with io.BytesIO(common_bytes_full) as stream:
        target = ELFFile(stream)
        require(target.little_endian, "common target is not little-endian")
        text = target.get_section_by_name(".text").data()
        common = {symbol.name: text[symbol["st_value"]:symbol["st_value"] + symbol["st_size"]] for symbol in target.get_section_by_name(".symtab").iter_symbols() if symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_size"]}
    header = common_bytes_full[:shared.EHDR.size]
    options = SimpleNamespace(no_context=True, toolchain=args.toolchain, runner=args.runner)
    code, symbols, proofs = bytearray(), [], []
    for entry, raw, proof in prove_all(catalogue, args, owners, common, options):
        while len(code) % 8:
            code.append(0)
        symbols.append((entry["name"], len(code), len(raw), 0x12, 1))
        code.extend(raw)
        proofs.append(proof)
    # shared functions proven by their owner level's full build (target_proven)
    extra, skipped = target_proven(owners, common, {entry["name"] for entry in catalogue})
    for name, raw, proof in extra:
        while len(code) % 8:
            code.append(0)
        symbols.append((name, len(code), len(raw), 0x12, 1))
        code.extend(raw)
        proofs.append(proof)
    for line in skipped:
        print("common C, not counted: " + line)
    blob =shared.build_elf(header, [(".text", shared.SHT_PROGBITS, shared.SHF_ALLOC | shared.SHF_EXEC, 8, bytes(code), len(code))], symbols)
    output.parent.mkdir(parents=True, exist_ok=True)
    temporary = output.with_suffix(".o.tmp")
    temporary.write_bytes(blob)
    temporary.replace(output)
    asm = [proof for proof in proofs if proof["inline_asm"]]
    report = {"pure_c_bytes": sum(proof["size"] for proof in proofs), "pure_c_functions": len(proofs),
              "inline_asm_bytes": sum(proof["size"] for proof in asm), "inline_asm_functions": len(asm),
              "base_sha256": digest(blob), "common_target_sha256": digest(common_bytes_full), "functions": proofs}
    output.with_suffix(".proof.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    report["level_target_functions"] = len(extra)
    print(f"MATCH common C: {report['pure_c_functions']} functions, {report['pure_c_bytes']} source bytes "
          f"({report['inline_asm_functions']} functions, {report['inline_asm_bytes']} bytes with inline asm; "
          f"{len(extra)} proven by a level target's build); zero masks, canonical owners")


if __name__ == "__main__":
    try:
        main()
    except (ValueError, OSError, KeyError) as error:
        raise SystemExit("ERROR: " + str(error))
