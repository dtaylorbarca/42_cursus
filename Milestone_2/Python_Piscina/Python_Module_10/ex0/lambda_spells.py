def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    changed = sorted(artifacts, key=lambda x: x['power'], reverse=True)
    return changed


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    filtered: list[dict] = list(
        filter(lambda x: x['power'] >= min_power, mages))
    return filtered


def spell_transformer(spells: list[str]) -> list[str]:
    changed = list(map(lambda x: f"*{x}*", spells))
    return changed


def mage_stats(mages: list[dict]) -> dict:
    max_power: int = max(mages, key=lambda x: x['power'])['power']
    min_power: int = min(mages, key=lambda x: x['power'])['power']
    average = round((max_power + min_power) / 2, 2)
    return {'max_power': max_power,
            'min_power': min_power,
            'avg_power': average}


def main():
    print("---  RUNNING MAGE & ARTIFACT SYSTEM TEST  ---\n")

    sample_artifacts = [
        {'name': 'Amulet of Fire', 'power': 45},
        {'name': 'Staff of the Archmage', 'power': 99},
        {'name': 'Orb of Shadows', 'power': 75}
    ]

    sample_mages = [
        {'name': 'Gandalf', 'power': 95},
        {'name': 'Saruman', 'power': 90},
        {'name': 'Radagast', 'power': 60},
        {'name': 'Apprentice Ron', 'power': 15}
    ]

    sample_spells = ['fireball', 'teleport', 'frostbolt']

    print("1. Testing artifact_sorter (Sorting high-to-low power via lambda):")
    sorted_artifacts = artifact_sorter(sample_artifacts)
    for artifact in sorted_artifacts:
        print(f"   - {artifact['name']}: {artifact['power']} power")
    print()

    min_threshold = 50
    print(
        f"2. Testing power_filter (Filtering for power >= {min_threshold} "
        "via lambda):")
    filtered_mages = power_filter(sample_mages, min_threshold)
    for mage in filtered_mages:
        print(f"   - {mage['name']} stays (Power: {mage['power']})")
    print()

    print("3. Testing spell_transformer (Wrapping strings in asterisks via "
          "lambda):")
    transformed_spells = spell_transformer(sample_spells)
    print(f"   Original:    {sample_spells}")
    print(f"   Transformed: {transformed_spells}")
    print()

    print("4. Testing mage_stats (Extracting max, min, and calculating "
          "average):")
    stats = mage_stats(sample_mages)
    print(f"   - Max Power:     {stats['max_power']}")
    print(f"   - Min Power:     {stats['min_power']}")
    print(f"   - Midpoint Avg:  {stats['avg_power']}")
    print()


if __name__ == "__main__":
    main()
