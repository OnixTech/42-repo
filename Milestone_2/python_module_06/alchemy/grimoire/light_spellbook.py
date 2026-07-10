def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    from . import light_validator
    name = spell_name

    return [name, light_validator.validate_ingredients(ingredients)]
