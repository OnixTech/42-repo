import sys


def main() -> None:

    inventory = {}
    i = 1
    while i < len(sys.argv):
        item = sys.argv[i].split(":")
        
        if len(item) != 2:
            print(f"Error - invalid parameter '{sys.argv[i]}'")
        else:
            try:
                if item[0] in inventory:
                    print(f"Redundant item '{item[0]}' - discarding")
                else:
                    inventory[item[0]] = int(item[1])
            except ValueError as e:
                print(f"Quantity error for '{item[0]}': {e}")
        i += 1

    elements = len(inventory)
    total = sum(inventory.values())
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    print(f"Total quantity of the {elements} items: {total}")

    for element in inventory:
        percentage = round((inventory[element] / total * 100), 1)
        print(f"Item {element} represents {percentage}%")

    most = list(inventory.keys())[0]
    least = list(inventory.keys())[0]
    for item in inventory:
        if inventory[most] < inventory[item]:
            most = item

        if inventory[least] > inventory[item]:
            least = item

    print(f"Item most abundant: {most} with quantity {inventory[most]}")
    print(f"Item least abundant: {least} with quantity {inventory[least]}")
    inventory.update({"New item": 87})
    print(f"Update inventory: {inventory}")


if __name__ == "__main__":
    main()
