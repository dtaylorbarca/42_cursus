import importlib.metadata
import importlib.util


def check_dependencies() -> list[str]:
    missing: list[str] = []
    print("Checking dependencies:")
    packages = ["pandas", "numpy", "matplotlib"]
    descriptions = {
        "pandas": "Data manipulation ready",
        "numpy": "Numerical computation ready",
        "matplotlib": "Visualization ready"
    }
    for package in packages:
        if importlib.util.find_spec(package) is not None:
            print(f"[OK] {package}"
                  f" ({importlib.metadata.version(package)})"
                  f" - {descriptions[package]}")
        else:
            print(f"[MISSING] {package} - "
                  f"{descriptions[package].replace('ready', 'not ready')}")
            missing.append(package)
    return missing


def analyze() -> None:
    import pandas as pd
    import numpy as np
    import matplotlib.pyplot as plt

    print("\nAnalyzing Matrix data...")
    x = np.linspace(0, 4 * np.pi, 1000)
    raw_data = np.sin(x)
    print("Processing 1000 data points...")
    data = pd.DataFrame({"x": x, "signal": raw_data})
    print("Generating visualization...")
    plt.plot(data["x"], data["signal"])
    plt.title("Matrix Signal Analysis")
    plt.xlabel("Radians")
    plt.ylabel("Amplitude")
    plt.axhline(
        y=data["signal"].mean(),
        color="r",
        label=f'Mean: {data["signal"].mean():.2f}'
    )
    plt.grid(True, which='both')
    plt.legend()
    plt.tight_layout()
    print("\nAnalysis complete!")
    plt.savefig("matrix_analysis.png")
    print("Results saved to: matrix_analysis.png")


def main() -> None:
    print("\nLOADING STATUS: Loading programs...\n")
    missing = check_dependencies()
    if not missing:
        analyze()
    else:
        missed = ' '.join(missing)
        print(f"\nDependencies missing: {missed}")
        print("\nTo install them:")
        print("   Using pip:")
        print("         pip install -r requirements.txt")
        print("\n   Using poetry:")
        print("         poetry install")
        print("\nThen run this program again.")


if __name__ == "__main__":
    main()
