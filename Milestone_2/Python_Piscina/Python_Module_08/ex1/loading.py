import importlib.metadata


missing: list[str] = []
try:
    import pandas as pd
    print(f"[OK] pandas ({importlib.metadata.version('pandas')})- "
          "Data manipulation ready")
except ImportError:
    print("[MISSING] pandas - Data manipulation not ready")
    missing.append('pandas')
try:
    import numpy as np
    print(f"[OK] numpy ({importlib.metadata.version('numpy')}) - "
          "Numerical computation ready")
except ImportError:
    print("[MISSING] numpy - Numerical computation not ready")
    missing.append('numpy')
try:
    import matplotlib.pyplot as plt
    print(f"[OK] matplotlib ({importlib.metadata.version('matplotlib')}) - "
          "Visualization ready")
except ImportError:
    print("[MISSING] matplotlib - Visualization not ready")
    missing.append('matplotlib')

if missing:
    missed = ' '.join(missing)
    print(f"\nDependencies missing: {missed}")
    print("\nTo install them:")
    print("   Using pip:")
    print("         pip install -r requirements.txt")
    print("\n   Using poetry:")
    print("         poetry install")
    print("\nThen run this program again.")
else:
    print("\nAnalyzing Matrix data...")
    raw_data = np.random.randn(1000)
    print("Processing 1000 data points...")
    data = pd.DataFrame(raw_data)
    print("Generating visualization...")
    plt.plot(data)
    print("\nAnalysis complete!")
    plt.savefig("matrix_analysis.png")
    print("Results saved to: matrix_analysis.png")
