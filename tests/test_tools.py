"""Unit tests for tools/ that need no toolchain and no game data.

  python3 -m unittest discover -s tests
"""
import os
import re
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(0, str(ROOT / "tests"))

import build_text  # noqa: E402
import check_repository  # noqa: E402
import ee29  # noqa: E402
import srcfiles  # noqa: E402
import targets  # noqa: E402

SHA1 = {
    "frontbin": "3bc94ee895e4b4af9b5602a229af599c1103b542",
    "boot_elf": "487975305f8a263c750dfede50391b575ed07835",
    "i5bootn": "71f3ecfc54c3d24d1475ef9efe8228fbfe59d65f",
}


class TargetsTest(unittest.TestCase):
    def test_three_programs_and_their_sha1s(self):
        self.assertEqual(set(targets.TARGETS), set(SHA1))
        for name, sha1 in SHA1.items():
            self.assertEqual(targets.TARGETS[name].sha1, sha1)

    def test_tables_exist(self):
        for t in targets.TARGETS.values():
            for attr in ("files", "parts", "divs_nops", "sq_ra_funcs", "symbol_addrs",
                         "symbols_resolved", "yaml", "ld"):
                self.assertTrue(os.path.isfile(t.path(attr)), f"{t.name}.{attr}: {getattr(t, attr)}")

    def test_yaml_names_the_same_sha1(self):
        for t in targets.TARGETS.values():
            m = re.search(r"^sha1:\s*([0-9A-Fa-f]{40})", open(t.path("yaml")).read(), re.M)
            self.assertIsNotNone(m, t.yaml)
            self.assertEqual(m.group(1).lower(), t.sha1)

    def test_units_do_not_overlap(self):
        for t in targets.TARGETS.values():
            spans = sorted((u.start, u.end) for u in t.units)
            for (_, end), (start, _) in zip(spans, spans[1:]):
                self.assertLessEqual(end, start, t.name)

    def test_from_argv_strips_the_option(self):
        argv = ["tool", "--target", "boot_elf", "x"]
        old = os.environ.get("UYA_TARGET")
        try:
            t = targets.from_argv(argv)
            self.assertEqual(t.name, "boot_elf")
            self.assertEqual(argv, ["tool", "x"])
            argv = ["tool", "--target=i5bootn"]
            self.assertEqual(targets.from_argv(argv).name, "i5bootn")
        finally:
            if old is None:
                os.environ.pop("UYA_TARGET", None)
            else:
                os.environ["UYA_TARGET"] = old

    def test_for_function_address(self):
        names = {t.name for t in targets.for_function_address(0x116F80)}
        self.assertEqual(names, {"boot_elf"})


class SourceListTest(unittest.TestCase):
    def test_file_lists_are_sorted_and_in_their_units(self):
        for t in targets.TARGETS.values():
            files = srcfiles.read_file_list(t.path("files"))
            self.assertTrue(files, t.name)
            starts = [s for _, s in files]
            self.assertEqual(starts, sorted(starts), t.name)
            for rel, start in files:
                self.assertIsNotNone(t.unit_for(start), f"{t.name}: {rel} at 0x{start:X}")

    def test_file_for_address(self):
        files = [("a.c", 0x100), ("b.c", 0x200)]
        self.assertEqual(srcfiles.file_for_address(files, 0x1FF), "a.c")
        self.assertEqual(srcfiles.file_for_address(files, 0x200), "b.c")


class FlagTableTest(unittest.TestCase):
    def write(self, text):
        fd, path = tempfile.mkstemp(suffix=".txt")
        with os.fdopen(fd, "w") as f:
            f.write(text)
        self.addCleanup(os.remove, path)
        return path

    def test_read_parts_and_lookup(self):
        parts = build_text.read_parts(self.write(
            "# comment\n00100000 -O2 -G8\n00100010 -O2 -G8 @ps2as  # one function\n00100018 -O2 -G8\n"))
        self.assertEqual(build_text.flags_for(parts, 0x100004), ["-O2", "-G8"])
        self.assertEqual(build_text.flags_for(parts, 0x100010), ["-O2", "-G8", "@ps2as"])
        self.assertEqual(build_text.flags_for(parts, 0x100018), ["-O2", "-G8"])

    def test_file_slices_group_runs_of_equal_flags(self):
        parts = [(0x0, ["-O2"]), (0x20, ["-O1"]), (0x40, ["-O2"])]
        chunks = [(0x0, 1, ""), (0x10, 2, ""), (0x20, 3, ""), (0x40, 4, ""), (0x50, 5, "")]
        self.assertEqual(build_text.file_slices(chunks, parts),
                         [(["-O2"], [0, 1]), (["-O1"], [2]), (["-O2"], [3, 4])])

    def test_pseudo_flags(self):
        cc = os.path.join("tc", "bin", "ee-gcc2953.exe")
        out = build_text.expand_flags(["-O2", "@ps2as", "@ee29"], cc)
        self.assertEqual(out[0], "-O2")
        self.assertTrue(out[1].startswith("-B") and out[1].endswith("Ps2Ee"))
        self.assertIn("-DNO_MACRO_INC", out)
        self.assertNotIn("@ee29", out)
        self.assertTrue(ee29.wanted(["-O2", "@ee29"]))
        self.assertFalse(ee29.wanted(["-O2"]))

    def test_every_flag_table_parses(self):
        for t in targets.TARGETS.values():
            parts = build_text.read_parts(t.path("parts"))
            self.assertTrue(parts, t.name)


class RepositoryCheckTest(unittest.TestCase):
    def test_tables_check_passes(self):
        errors = []
        check_repository.check_tables(errors)
        self.assertEqual(errors, [])

    def test_game_data_check_flags_an_elf(self):
        with tempfile.TemporaryDirectory() as d:
            Path(d, "x.txt").write_bytes(b"\x7fELF\x01\x01")
            Path(d, "frontbin.elf").write_bytes(b"")
            old_root, old_list = check_repository.ROOT, check_repository.tracked_files
            check_repository.ROOT = Path(d)
            check_repository.tracked_files = lambda: ["x.txt", "frontbin.elf"]
            try:
                errors = []
                check_repository.check_game_data(errors)
            finally:
                check_repository.ROOT, check_repository.tracked_files = old_root, old_list
            self.assertTrue(any("x.txt" in e and "ELF" in e for e in errors), errors)
            self.assertTrue(any("frontbin.elf" in e for e in errors), errors)


if __name__ == "__main__":
    unittest.main()
