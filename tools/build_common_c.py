"""Compile common-level C, prove its retail bytes, and build a partial objdiff base.

Requires personal level ELFs, the original 51 level target objects, and their
split common.o. Never uses retail instructions to fill missing base functions.
"""
import argparse
import hashlib
import io
import json
import re
from pathlib import Path
from types import SimpleNamespace

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

import pr_check
import split_shared_levels as shared
import try_func as matching


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
    require(not re.search(r"\b(?:__asm__|__asm|asm|INCLUDE_ASM|INCLUDE_RODATA|ASM_FUNC|LINKER_REMNANT)\b", code), "assembly source cannot receive C credit")
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
        "strict_equal": True, "masked_words": 0, "canonical_owner": True,
        "relocations": relocations,
    }
    return raw, proof


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--levels-dir", required=True, type=Path)
    parser.add_argument("--targets-dir", required=True, type=Path)
    parser.add_argument("--common-target", required=True, type=Path)
    parser.add_argument("--catalogue", type=Path, default=ROOT / "tools/common_c.json")
    parser.add_argument("--output", type=Path, default=ROOT / "build/objdiff/base/common.o")
    parser.add_argument("--toolchain", default=matching.DEFAULT_TOOLCHAIN)
    parser.add_argument("--runner")
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
    for entry in catalogue:
        raw, proof = compile_entry(entry, args.levels_dir, args.targets_dir, owners, common, options)
        while len(code) % 8:
            code.append(0)
        symbols.append((entry["name"], len(code), len(raw), 0x12, 1))
        code.extend(raw)
        proofs.append(proof)
    blob = shared.build_elf(header, [(".text", shared.SHT_PROGBITS, shared.SHF_ALLOC | shared.SHF_EXEC, 8, bytes(code), len(code))], symbols)
    output.parent.mkdir(parents=True, exist_ok=True)
    temporary = output.with_suffix(".o.tmp")
    temporary.write_bytes(blob)
    temporary.replace(output)
    report = {"pure_c_bytes": sum(proof["size"] for proof in proofs), "pure_c_functions": len(proofs), "base_sha256": digest(blob), "common_target_sha256": digest(common_bytes_full), "functions": proofs}
    output.with_suffix(".proof.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"MATCH common C: {report['pure_c_functions']} functions, {report['pure_c_bytes']} source bytes; zero masks, canonical owners")


if __name__ == "__main__":
    try:
        main()
    except (ValueError, OSError, KeyError) as error:
        raise SystemExit("ERROR: " + str(error))
