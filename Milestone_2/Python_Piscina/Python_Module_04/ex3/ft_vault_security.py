def secure_archive(file_name: str, action: str = "read", content: str = "") -> tuple[bool, str]:
    try:
        with open(file_name, "r+") as f:
            if action == "read":
                content = f.read()
                return (True, content)
            elif action == "write":
                f.write(content)
                return (True, "Content successfully written to a file")
            else:
                return (False, "Only read and write can be performed")
    except PermissionError as e:
        return (False, str(e))
    except FileNotFoundError as e:
        return (False, str(e))


def main() -> None:
    print("=== Cyber Archives Security ===\n")

    print("Using 'secure_archive' to read from a nonexistent file:")
    result: tuple[bool, str] = secure_archive("/non/existing/file")
    print(result)
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    result: tuple[bool, str] = secure_archive("/etc/passwd")
    print(result)
    print("\nUsing 'secure_archive' to read from a regular file:")
    result: tuple[bool, str] = secure_archive("ancient_fragment.txt", "read")
    print(result)
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    result: tuple[bool, str] = secure_archive("ancient_fragment.txt", "write", "Hello this has been overwritten")
    print(result)


if __name__ == "__main__":
    main()
