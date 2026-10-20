#!/usr/bin/env python3
"""progress.py: how much of each program is final source, and the progress report.

    python3 tools/progress.py                  # counts from src/, and the committed report's totals
    python3 tools/progress.py --check          # progress/report.json is a valid objdiff report (CI)
    python3 tools/progress.py --write build/report.json   # install a new report (maintainers)
    python3 tools/progress.py --readme         # also refresh the table in README.md

Counts come from the sources, the same way tools/pr_check.py counts them (it is run once per
program with --no-compile --no-git): functions in C, hand-written assembly (ASM_FUNC), linker
remnants (LINKER_REMNANT) and what is still INCLUDE_ASM. They need no game data. What counts as
matched is still the full build's MATCH lines: src/ only holds code that builds byte-identical.

progress/report.json is objdiff's report (the format decomp.dev reads, as in rac1-decomp and
rac2-decomp). The self-hosted CI job (.github/workflows/build-and-report.yml) builds it with
`objdiff-cli report generate -o build/report.json` after `make objdiff`; a maintainer copies it
here with --write and commits it on its own. objdiff.json, its configuration, stays in the
repository root, where objdiff looks for it.
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import targets  # noqa: E402

REPORT = os.path.join(ROOT, "progress", "report.json")
README = os.path.join(ROOT, "README.md")
BEGIN, END = "<!-- progress:begin (tools/progress.py --readme) -->", "<!-- progress:end -->"


def counts(name):
    """{'c', 'asm_func', 'remnant', 'include_asm'} for one program, from tools/pr_check.py."""
    r = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "pr_check.py"), "--target", name,
                        "--no-compile", "--no-git"], cwd=ROOT, capture_output=True, text=True)
    out = r.stdout + r.stderr
    m = re.search(r"^(\d+) functions in C, (\d+) INCLUDE_ASM", out, re.M)
    if not m:
        sys.exit("progress: tools/pr_check.py --target %s printed no counts:\n%s" % (name, out[-2000:]))
    h = re.search(r"^(\d+) hand-written asm functions \(ASM_FUNC\), (\d+) linker remnants", out, re.M)
    return {"c": int(m.group(1)), "include_asm": int(m.group(2)),
            "asm_func": int(h.group(1)) if h else 0, "remnant": int(h.group(2)) if h else 0,
            "ok": r.returncode == 0}


def table(rows):
    lines = ["| Program | Functions | Final source | in C | ASM_FUNC | LINKER_REMNANT | INCLUDE_ASM |",
             "| --- | ---: | ---: | ---: | ---: | ---: | ---: |"]
    for name, c in rows:
        total = c["c"] + c["asm_func"] + c["remnant"] + c["include_asm"]
        done = total - c["include_asm"]
        lines.append("| %s | %d | %d (%.1f%%) | %d | %d | %d | %d |" % (
            name, total, done, 100.0 * done / total if total else 0, c["c"], c["asm_func"],
            c["remnant"], c["include_asm"]))
    return "\n".join(lines)


def check_report(path):
    """Problems with an objdiff report ([] if it looks right)."""
    try:
        d = json.load(open(path, encoding="utf-8"))
    except (OSError, ValueError) as e:
        return ["%s: %s" % (os.path.relpath(path, ROOT), e)]
    problems = []
    for key in ("measures", "units"):
        if key not in d:
            problems.append("%s: no %r (not an objdiff report)" % (os.path.relpath(path, ROOT), key))
    m = d.get("measures", {})
    for key in ("total_code", "matched_code", "total_functions", "matched_functions"):
        if key not in m:
            problems.append("%s: measures has no %r" % (os.path.relpath(path, ROOT), key))
    if not problems and int(m["matched_code"]) > int(m["total_code"]):
        problems.append("%s: matched_code exceeds total_code" % os.path.relpath(path, ROOT))
    return problems


def summary(path):
    m = json.load(open(path, encoding="utf-8"))["measures"]
    return ("%s: %s of %s functions, %.2f%% of the code (objdiff, every program and level)"
            % (os.path.relpath(path, ROOT), m.get("matched_functions"), m.get("total_functions"),
               float(m.get("matched_code_percent", 0))))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true", help="validate progress/report.json and exit")
    ap.add_argument("--write", metavar="REPORT", help="copy a new objdiff report to progress/report.json")
    ap.add_argument("--readme", action="store_true", help="refresh the progress table in README.md")
    a = ap.parse_args()

    if a.write:
        problems = check_report(a.write)
        if problems:
            sys.exit("\n".join(problems))
        os.makedirs(os.path.dirname(REPORT), exist_ok=True)
        shutil.copyfile(a.write, REPORT)
        print("wrote", os.path.relpath(REPORT, ROOT))
    if a.check:
        problems = check_report(REPORT)
        for p in problems:
            print("error:", p)
        if not problems:
            print(summary(REPORT))
            print("OK")
        sys.exit(1 if problems else 0)

    rows = [(name, counts(name)) for name in targets.TARGETS]
    text = table(rows)
    print(text)
    if os.path.exists(REPORT) and not check_report(REPORT):
        print()
        print(summary(REPORT))
    if a.readme:
        readme = open(README, encoding="utf-8").read()
        if BEGIN not in readme or END not in readme:
            sys.exit("README.md has no %s ... %s block" % (BEGIN, END))
        head, rest = readme.split(BEGIN, 1)
        _, tail = rest.split(END, 1)
        open(README, "w", encoding="utf-8", newline="\n").write(head + BEGIN + "\n" + text + "\n" + END + tail)
        print("updated README.md")
    sys.exit(0 if all(c["ok"] for _, c in rows) else 1)


if __name__ == "__main__":
    main()
