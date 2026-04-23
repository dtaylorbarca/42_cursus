from .light_spellbook import light_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed = light_spell_allowed_ingredients()
    valid = any(i in ingredients.lower() for i in allowed)
    keyword = 'VALID' if valid else 'INVALID'
    return f'{ingredients} - {keyword}'
