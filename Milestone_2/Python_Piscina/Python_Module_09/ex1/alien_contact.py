from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from typing import Optional, Self


class ContactType(str, Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime = Field(default=None)
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: ContactType = Field()
    signal_strength: float = Field(..., ge=0.0, le=10.0)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: Optional[str] = Field(max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode="after")
    def custom_validation_rules(self) -> Self:
        if self.contact_id[:2] != "AC":
            raise ValueError('Contact ID must start with "AC" (Alien Contact)')
        if not self.is_verified:
            raise ValueError("Physical contact reports must be verified")
        if (self.contact_type == "telepathic" and
                self.witness_count < 3):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses")
        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError(
                "Strong signals (> 7.0) should include received messages")
        return self


def main() -> None:
    print("Alien Contact Log Validation")
    print("======================================")
    print("Valid contact report:")
    try:
        alien_contact = AlienContact(
            contact_id="AC_2024_001",
            location="Area 51, Nevada",
            contact_type="radio",
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received="'Greetings from Zeta Reticuli'",
            is_verified=True
        )
        print(f"ID: {alien_contact.contact_id}")
        print(f"Type: {alien_contact.contact_type}")
        print(f"Location: {alien_contact.location}")
        print(f"Signal: {alien_contact.signal_strength}/10")
        print(f"Duration: {alien_contact.duration_minutes} minutes")
        print(f"Witnesses: {alien_contact.witness_count}")
        print(f"Message: '{alien_contact.message_received}'")
    except ValueError as e:
        print(e)
    print("======================================")
    print("Expected validation error:")
    try:
        alien_contact = AlienContact(
            contact_id="AC_2024_001",
            location="Area 51, Nevada",
            contact_type="telepathic",
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=1,
            message_received="'Greetings from Zeta Reticuli'",
            is_verified=True
        )
        print(f"ID: {alien_contact.contact_id}")
        print(f"Type: {alien_contact.contact_type}")
        print(f"Location: {alien_contact.location}")
        print(f"Signal: {alien_contact.signal_strength}/10")
        print(f"Duration: {alien_contact.duration_minutes} minutes")
        print(f"Witnesses: {alien_contact.witness_count}")
        print(f"Message: '{alien_contact.message_received}'")
    except ValueError as e:
        print(e)


if __name__ == "__main__":
    main()
