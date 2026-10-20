#!/usr/bin/env python3
"""try_func.py: the old name of tools/check.py (checking one function), kept so existing
commands, scripts and imports keep working. Same options, same output.

    python tools/try_func.py ...   ==   python tools/check.py ...
"""
import os
import runpy
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
if _HERE not in sys.path:
    sys.path.insert(0, _HERE)

if __name__ == "__main__":
    runpy.run_path(os.path.join(_HERE, "check.py"), run_name="__main__")
else:
    # `import try_func` gives the very module tools/check.py is
    import check as _impl  # noqa: E402
    sys.modules[__name__] = _impl
    # and for loaders that keep this module object (importlib's spec_from_file_location)
    globals().update({k: v for k, v in vars(_impl).items() if not k.startswith("__")})
