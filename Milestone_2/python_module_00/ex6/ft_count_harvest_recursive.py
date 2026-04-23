def ft_count_harvest_recursive(i=1, days=None):
    if days is None:
        days = int(input("Days until harverst: "))
    print(f"Day {i}")
    if i == days:
        print("Harvest time!")
        return
    return ft_count_harvest_recursive(i + 1, days)
