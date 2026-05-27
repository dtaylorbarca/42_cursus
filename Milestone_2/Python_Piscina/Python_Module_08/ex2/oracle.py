import os
import sys
from dotenv import load_dotenv


def check_harcoded_secrets(file) -> bool:
    secret_keys = ["DATABASE_URL", "API_KEY"]

    with open(file, 'r') as file:
        lines = file.readlines()

    for line in lines:
        clean_line = line.strip()
        for key in secret_keys:
            if clean_line.startswith(key) and "=" in clean_line:
                value = clean_line.split("=", 1)[1].strip()
                if (("os.getenv" not in value) and ("os.environ" not in value)
                        and value != ""):
                    if ((value.startswith('"') and value.endswith('"')) or
                            (value.startswith("'") and value.endswith("'"))):
                        return False
    return True


def env_configuration() -> bool:
    variables = [
        "MATRIX_MODE",
        "DATABASE_URL",
        "API_KEY",
        "LOG_LEVEL",
        "ZION_ENDPOINT"
    ]
    for key in variables:
        if not os.getenv(key):
            return False
        if key == "MATRIX_MODE":
            if (os.getenv(key) != "development" and
                    os.getenv(key) != "production"):
                return False
        if key == "DATABASE_URL":
            db_url = os.getenv("DATABASE_URL")
            if not db_url or "://" not in db_url:
                return False
    return True


def main() -> None:
    print("ORACLE STATUS: Reading the Matrix...")
    load_dotenv()

    mode = os.getenv('MATRIX_MODE', 'development')
    database = os.getenv('DATABASE_URL')
    api = os.getenv('API_KEY')
    log = os.getenv('LOG_LEVEL', 'DEBUG')
    zion = os.getenv('ZION_ENDPOINT_URL')

    print("\nConfiguration loaded:")
    print(f"Mode: {mode}")
    print(
        "Database: "
        f"{'Connected to local instance' if database else 'Not connected'}")
    print(f"API Access: {'Authenticated' if api else 'Not authenticated'}")
    print(f"Log Level: {log}")
    print(f"Zion Network: {'Online' if zion else 'Offline'}")

    print("\nEnvironment security check:")
    if check_harcoded_secrets(sys.argv[0]):
        print("[OK] No hardcoded secrets detected")
    else:
        print("[FAIL] hardcoded secrets detected in source code")
    if env_configuration():
        print("[OK] .env file properly configured")
    else:
        print("[FAIL] .env file not properly configured")


if __name__ == "__main__":
    main()
