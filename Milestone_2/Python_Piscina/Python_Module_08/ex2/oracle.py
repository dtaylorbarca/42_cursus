import os
import sys
from dotenv import load_dotenv


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
        f"Database: {'Connected to local instance' if database else 'Not connected'}")
    print(f"API Access: {'Authenticated' if api else 'Not authenticated'}")
    print(f"Log Level: {log}")
    print(f"Zion Network: {'Online' if zion else 'Offline'}")


if __name__ == "__main__":
    main()
