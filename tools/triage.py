#!/usr/bin/env python3
"""triage.py: the old name of tools/todo.py (listing the functions still to match), kept so existing
commands, scripts and imports keep working. Same options, same output.

    python tools/triage.py ...   ==   python tools/todo.py ...
"""
import os
import runpy
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
if _HERE not in sys.path:
    sys.path.insert(0, _HERE)

if __name__ == "__main__":
    runpy.run_path(os.path.join(_HERE, "todo.py"), run_name="__main__")
else:
    # `import triage` gives the very module tools/todo.py is
    import todo as _impl  # noqa: E402
    sys.modules[__name__] = _impl
    # and for loaders that keep this module object (importlib's spec_from_file_location)
    globals().update({k: v for k, v in vars(_impl).items() if not k.startswith("__")})
