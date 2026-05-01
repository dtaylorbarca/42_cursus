import importlib

try:
    import pandas as pd
    print(f"[OK] pandas ({pd.__version__})- Data manipulation ready")
except ImportError:
    print("[MISSING] pandas - Data manipulation not ready")
try:
    import requests
    print(f"[OK] requests ({requests.__version__})- Network access ready")
except ImportError:
    print("[MISSING] requests - Network access ready")

import sys
import matplotlib

