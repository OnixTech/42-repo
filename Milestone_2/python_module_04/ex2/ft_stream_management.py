import sys
import typing


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        file: typing.IO[str] = open(filename, "r")
    except OSError as err:
        sys.stderr.write(f"Error opening file '{filename}': {err}\n")
        return

    print("---\n")
    content = file.read()
    print(content)
    print("\n---")

    file.close()
    print(f"File '{filename}' closed.\n")

    print("Transform data:")

    new_content = ""
    for c in content:
        if c == "\n":
            new_content += "#\n"
        else:
            new_content += c

    print("---\n")
    print(new_content)
    print("\n---")

    sys.stdout.write("Enter your new file name (or empty): ")
    sys.stdout.flush()
    new_name = sys.stdin.readline()

    if new_name != "":
        new_name = new_name[:-1]
        # delete the las character '\n' [start:end]
        # in negatives indexs '-1' is the last charater
        new_file: typing.IO[str] = open(new_name, "w")
        new_file.write(new_content)
        new_file.close()

        print(f"Archive saved to '{new_name}'")
    else:
        print("Not saving data.")


if __name__ == "__main__":
    main()
