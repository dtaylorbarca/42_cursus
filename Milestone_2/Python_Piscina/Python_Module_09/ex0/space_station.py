from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
from typing import Optional


class SpaceStation(BaseModel):
    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0.0, le=100.00)
    oxygen_level: float = Field(..., ge=0.0, le=100.00)
    last_maintenance: Optional[datetime] = Field(default=None)
    is_operational: bool = Field(default=True)
    notes: Optional[str] = Field(max_length=200, default=None)


def main() -> None:
    print("Space Station Data Validation")
    print("====================================")
    try:
        space_station = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3,
            is_operational=True
        )
        print("Valid station created")
        print(f"ID: {space_station.station_id}")
        print(f"Name: {space_station.name}")
        if space_station.crew_size > 1:
            print(f"Crew: {space_station.crew_size} people")
        else:
            print(f"Crew: {space_station.crew_size} person")
        print(f"Power: {space_station.power_level}%")
        print(f"Oxygen: {space_station.oxygen_level}%")
        print(
            f"Status: {"Operational" if space_station.is_operational
                       else "Nonoperational"}")
    except ValidationError as e:
        print(e)
    print("====================================")
    print("Expected validation error")
    try:
        space_station_2 = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=25,
            power_level=85.5,
            oxygen_level=92.3,
            is_operational=True
        )
        print(space_station_2)
    except ValidationError as e:
        print(e)


if __name__ == "__main__":
    main()
