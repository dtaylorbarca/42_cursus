def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    sorted(artifacts, key=lambda x: x['power'], reverse=True)
    return artifacts


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    filtered: list[dict] = list(filter(lambda x: x['power'] >= min_power, mages))
    return filtered

def spell_transformer(spells: list[str]) -> list[str]:
    changed = list(map(lambda x: f"*{x}*", spells))
    return changed


def mage_stats(mages: list[dict]) -> dict:
    max_power = max(mages, key=lambda x: x['power'])
    min_power = min(mages, key=lambda x: x['power'])
    average = (max_power + min_power)
