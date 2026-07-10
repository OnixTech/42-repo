def validate_ingredients(ingredients: str) -> str:
    from . import light_spellbook

    allowed = light_spellbook.light_spell_allowed_ingredients()
    for element in allowed:
        if element.lower() in ingredients.lower():
            return "VALID"
    return "INVALID"
