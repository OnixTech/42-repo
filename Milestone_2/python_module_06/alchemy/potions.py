import elements as base_elements
from . import elements as alchemy_elements


healing = "Healing potion brewed with "
strength = "Strength potion brewed with "

def healing_potion() -> str:
    earth = alchemy_elements.create_earth()
    air = alchemy_elements.create_air()
    return healing + f"'{earth}'" + " and " + f"'{air}'"


def strength_potion() -> str:
    fired = base_elements.create_fire()
    water = base_elements.create_water()
    return strength + f"'{fired}'" + " and " + f"'{water}'"
