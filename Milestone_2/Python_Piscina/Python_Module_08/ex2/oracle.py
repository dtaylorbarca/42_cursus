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


def env_configuration() -> tuple[bool, list[str]]:

    errors = []
    variables = [
        "MATRIX_MODE",
        "DATABASE_URL",
        "API_KEY",
        "LOG_LEVEL",
        "ZION_ENDPOINT_URL"
    ]
    config = {}
    for key in variables:
        value = os.getenv(key)
        if not value or value.strip() == "":
            errors.append(
                f"Missing required variable or empty value for: {key}")
        else:
            config[key] = value.strip()
    if errors:
        return False, errors

    if config["MATRIX_MODE"] not in ["development", "production"]:
        errors.append(f"MATRIX_MODE must be 'development' or 'production' "
                      f"(Got: '{config['MATRIX_MODE']}')")
    if "://" not in config["DATABASE_URL"]:
        errors.append(
            "DATABASE_URL is missing a valid protocol string structure "
            "(e.g., 'postgresql://')")
    if len(config["API_KEY"]) < 8:
        errors.append(
            "API_KEY is too short to be considered a secure mainframe access"
            " token")
    valid_log_levels = ["DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"]
    if config["LOG_LEVEL"] not in valid_log_levels:
        errors.append(f"LOG_LEVEL must be one of {valid_log_levels} "
                      f"(Got: '{config['LOG_LEVEL']}')")
    if (not (config["ZION_ENDPOINT_URL"].startswith("http://") or
             config["ZION_ENDPOINT_URL"].startswith("https://"))):
        errors.append(
            "ZION_ENDPOINT_URL must be a valid network URL starting with "
            "http:// or https://")
    if errors:
        return False, errors
    return True, []


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
    configured = env_configuration()
    if configured[0]:
        print("[OK] .env file properly configured")
    else:
        print("[FAIL] .env file not properly configured")
        for error in configured[1]:
            print(f"    {error}")


if __name__ == "__main__":
    main()
