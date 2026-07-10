from . import dark_validator


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    name = spell_name

    return [name, dark_validator.validate_ingredients(ingredients)]
