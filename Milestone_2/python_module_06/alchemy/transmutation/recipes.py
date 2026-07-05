from .. import elements as alchemy_elements
from .. import potions
from elements import create_fire


def lead_to_gold() -> str:
    air = alchemy_elements.create_air()
    strength = potions.strength_potion()
    fire = create_fire()
    return (f"Recipe tranmuting Lead to Gold: brew '{air}'"
            f" and '{strength}' mixed with '{fire}'")
