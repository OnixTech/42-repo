def secure_archive(filename: str,
                   action: str = "r",
                   content: str = "") -> tuple[bool, str]:
    try:
        with open(filename, action) as file:
            if action == "r":
                return (True, file.read())

            elif action == "w":
                file.write(content)
                return (True, "Content successfully written to file")

        return (False, "Invalid action")

    except OSError as err:
        return (False, str(err))


def main() -> None:
    print("=== Cyber Archives Security ===")

    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("nonexistent.txt", "r"))

    print("Using 'secure_archive' to read from a inaccessible file:")
    print(secure_archive("/etc/shadow", "r"))

    print("Using 'secure_archive' to read from a regular file:")
    file_result = secure_archive("file.txt", "r")
    print(file_result)

    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive("new_file.txt", "w", file_result[1]))


if __name__ == "__main__":
    main()
