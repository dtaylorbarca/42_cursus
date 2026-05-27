def secure_archive(file_name: str, action: str = "read",
                   content: str = "") -> tuple[bool, str]:
    try:
        if action == "read":
            with open(file_name, "r") as f:
                data = f.read()
                return (True, data)
        elif action == "write":
            with open(file_name, "w") as f:
                f.write(content)
                return (True, "Content successfully written to file")
        else:
            return (False, "Only read and write can be performed")
    except OSError as e:
        return (False, str(e))


def main() -> None:
    print("=== Cyber Archives Security ===\n")

    print("Using 'secure_archive' to read from a nonexistent file:")
    result: tuple[bool, str] = secure_archive("/non/existing/file")
    print(result)
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    result = secure_archive("/etc/shadow")
    print(result)
    print("\nUsing 'secure_archive' to read from a regular file:")
    result = secure_archive("ancient_fragment.txt", "read")
    print(result)
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    result = secure_archive("ancient_fragment.txt", "write", "Hello this has "
                            "been overwritten")
    print(result)


if __name__ == "__main__":
    main()
