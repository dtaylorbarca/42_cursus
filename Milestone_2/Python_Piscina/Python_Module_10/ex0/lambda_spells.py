from typing import cast, Any


def artifact_sorter(
        artifacts: list[
            dict[str, str | int]]) -> list[dict[str, str | int]]:
    changed = sorted(artifacts, key=lambda x: x['power'], reverse=True)
    return changed


def power_filter(mages: list[dict[str, str | int]],
                 min_power: int) -> list[dict[str, str | int]]:
    filtered: list[dict[str, str | int]] = list(
        filter(lambda x: cast(int, x['power']) >= min_power, mages))
    return filtered


def spell_transformer(spells: list[str]) -> list[str]:
    changed = list(map(lambda x: f"*{x}*", spells))
    return changed


def mage_stats(mages: list[dict[str, Any]]) -> dict[str, int | float]:
    max_power: int = max(mages, key=lambda x: x['power'])['power']
    min_power: int = min(mages, key=lambda x: x['power'])['power']
    average = round(sum(m['power'] for m in mages) / len(mages), 2)
    return {'max_power': max_power,
            'min_power': min_power,
            'avg_power': average}


def main() -> None:
    print("---  RUNNING MAGE & ARTIFACT SYSTEM TEST  ---\n")

    sample_artifacts: list[dict[str, str | int]] = [
        {'name': 'Shadow Blade', 'power': 97, 'type': 'accessory'},
        {'name': 'Ice Wand', 'power': 105, 'type': 'relic'},
        {'name': 'Storm Crown', 'power': 111, 'type': 'armor'},
        {'name': 'Storm Crown', 'power': 115, 'type': 'relic'}
    ]

    sample_mages: list[dict[str, str | int]] = [
        {'name': 'Jordan', 'power': 73, 'element': 'wind'},
        {'name': 'Morgan', 'power': 76, 'element': 'earth'},
        {'name': 'Phoenix', 'power': 59, 'element': 'wind'},
        {'name': 'Sage', 'power': 67, 'element': 'earth'},
        {'name': 'Alex', 'power': 55, 'element': 'shadow'}
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
