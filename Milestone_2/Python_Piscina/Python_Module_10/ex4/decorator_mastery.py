from typing import Any
import time
from collections.abc import Callable
from functools import wraps
from time import perf_counter


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def wrapper(target: str):
        print(f"Casting {func}...")
        start = perf_counter()
        func(target)
        end = perf_counter()
        execution_time = end - start
        print(f"Spell completed in {execution_time:.3f} seconds")
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorater(func: Callable):
        @wraps(func)
        def wrapper(power: int, spell_name: str) -> str:
            if power > min_power:
                return func(power, spell_name)
            else:
                return "Insufficient power for this spell"
        return wrapper
    return decorater


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable):
        @wraps(func)
        def wrapper():
            attempts = 0
            while attempts < max_attempts:
                try:
                    return func()
                except Exception:
                    attempts += 1
                    print("Spell failed, retrying ... "
                          f"(attempt {attempts}/{max_attempts})")
                    if attempts >= max_attempts:
                        return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        only_letters = True
        for x in name:
            if not x.isalpha() and x != " ":
                only_letters = False
        if not only_letters or len(name) < 3:
            return False
        return True

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        validate = power_validator(min_power=10)


def main() -> None:
    print("==================================================")
    print("        BEGINNING EX4: MASTER'S TOWER TESTS       ")
    print("==================================================")
    print("WARNING: This test may take up to ~1 second due to sleep timers.\n")

    # ==========================================
    # 1. TESTING SPELL TIMER
    # ==========================================
    print("--- 1. Testing Spell Timer ---")
    try:
        # Mock spell function to test execution tracking
        @spell_timer
        def cast_fireball(target: str) -> str:
            time.sleep(0.1)  # Simulate small delay to verify output formatting
            return f"Fireball cast at {target}!"

        # Call the decorated function
        result = cast_fireball("Training Dummy")
        print(f"Result: {result}")

        # Verify metadata preservation (functools.wraps test)
        print(
            f"Metadata Integrity Check - Name preserved: {cast_fireball.__name__ == 'cast_fireball'}")
    except NameError:
        print("Error: spell_timer decorator is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during timing evaluation: {e}")
    print()

    # ==========================================
    # 2. TESTING POWER VALIDATOR (Standalone)
    # ==========================================
    print("--- 2. Testing Power Validator ---")
    try:
        # Define a standalone function where the first parameter is power
        @power_validator(min_power=25)
        def basic_incantation(power: int, spell_name: str) -> str:
            return f"Successfully channelled {spell_name} at power {power}"

        print(f"Valid power check (30): {basic_incantation(30, 'Teleport')}")
        print(f"Invalid power check (15): {basic_incantation(15, 'Teleport')}")
        print(
            f"Metadata Integrity Check - Name preserved: {basic_incantation.__name__ == 'basic_incantation'}")
    except NameError:
        print("Error: power_validator decorator is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during validation processing: {e}")
    print()

    # ==========================================
    # 3. TESTING RETRY SPELL
    # ==========================================
    print("--- 3. Testing Retry Spell ---")
    try:
        failure_counter = 0

        # Create a mock spell that intentionally fails to trigger retry mechanics
        @retry_spell(max_attempts=3)
        def unstable_summon() -> str:
            global failure_counter
            failure_counter += 1
            if failure_counter < 2:
                raise RuntimeError("Mana stream unstable")
            return "Phoenix Summoned!"

        print("Testing a spell that fails once then succeeds:")
        print(f"Final Outcome: {unstable_summon()}")
        print()

        # Reset and test absolute failure paths
        @retry_spell(max_attempts=3)
        def doomed_ritual() -> str:
            raise ValueError("Void corruption detected")

        print("Testing an absolute failure path:")
        final_failure_outcome = doomed_ritual()
        print(f"Final Outcome: {final_failure_outcome}")
    except NameError:
        print("Error: retry_spell decorator is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during failure mitigation testing: {e}")
    print()

    # ==========================================
    # 4. TESTING MAGE GUILD CLASS
    # ==========================================
    print("--- 4. Testing Mage Guild Class ---")
    try:
        # Verify staticmethod validation paths
        print("Validating names via Static Method:")
        # At least 3 chars, letters/spaces
        print(
            f"  Is 'Gandalf' valid? {MageGuild.validate_mage_name('Gandalf')}")
        # Too short
        print(f"  Is 'X' valid?       {MageGuild.validate_mage_name('X')}")
        # Contains non-alpha digits
        print(
            f"  Is 'Mage_1' valid?  {MageGuild.validate_mage_name('Mage_1')}")
        print()

        # Instantiate the guild to evaluate bound instance methods and method decoration
        print("Testing instance method execution with integrated power validator:")
        guild_instance = MageGuild()

        # Test valid power trajectory (>= 10)
        print(
            f"  High power call (15): {guild_instance.cast_spell('Lightning', 15)}")
        # Test invalid power trajectory (< 10)
        print(
            f"  Low power call (5):   {guild_instance.cast_spell('Lightning', 5)}")
    except NameError:
        print("Error: MageGuild class definition is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during object factory validation: {e}")
    print()

    print("==================================================")
    print("             END OF EVALUATION MATRIX             ")
    print("==================================================")


if __name__ == "__main__":
    main()
