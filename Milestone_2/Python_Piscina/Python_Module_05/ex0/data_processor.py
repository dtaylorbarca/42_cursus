from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.data_queue: list[Any] = []
        self.data_rank: int = -1

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        try:
            self.data_queue[0]
        except IndexError:
            return (self.data_rank, "")
        self.data_rank += 1
        return (self.data_rank, self.data_queue.pop(0))


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            for x in data:
                if not isinstance(x, int) and not isinstance(x, float):
                    return False
        elif not isinstance(data, int) and not isinstance(data, float):
            return False
        return True

    def ingest(self, data: int | float | list[int | float]):
        if isinstance(data, list):
            for x in data:
                if not isinstance(x, int) and not isinstance(x, float):
                    raise Exception("Improper numeric data")
        elif not isinstance(data, int) and not isinstance(data, float):
            raise Exception("Improper numeric data")

        if isinstance(data, list):
            self.data_queue.extend([str(x) for x in data])
        else:
            self.data_queue.append(str(data))


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            for x in data:
                if not isinstance(x, str):
                    return False
        elif not isinstance(data, str):
            return False
        return True

    def ingest(self, data: str | list[str]):
        if isinstance(data, list):
            for x in data:
                if not isinstance(x, str):
                    raise Exception("Improper text data")
        elif not isinstance(data, str):
            raise Exception("Improper text data")
        if isinstance(data, list):
            self.data_queue.extend(data)
        else:
            self.data_queue.append(data)


class LogProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            for x in data:
                if isinstance(x, dict):
                    for y in x:
                        if not isinstance(y, str) or not isinstance(x[y], str):
                            return False
                else:
                    return False
        elif isinstance(data, dict):
            for x in data:
                if not isinstance(x, str) or not isinstance(data[x], str):
                    return False
        return True

    def ingest(self, data: dict[str, str] | list[dict[str, str]]):
        if isinstance(data, list):
            for x in data:
                if isinstance(x, dict):
                    for y in x:
                        if not isinstance(y, str) or not isinstance(x[y], str):
                            raise Exception("Improper log data")
                else:
                    raise Exception("Improper log data")
        elif isinstance(data, dict):
            for x in data:
                if not isinstance(x, str) or not isinstance(data[x], str):
                    raise Exception("Improper log data")

        str_convert = []
        if isinstance(data, list):
            for x in data:
                index = 0
                dict_str = ""
                for y in x:
                    if index < (len(x) - 1):
                        dict_str = dict_str + x[y] + ": "
                        index += 1
                    else:
                        dict_str = dict_str + x[y]
                str_convert.append(dict_str)
            self.data_queue.extend(str_convert)
        elif isinstance(data, dict):
            index = 0
            dict_str = ""
            for x in data:
                if index < (len(data) - 1):
                    dict_str = dict_str + data[x] + ": "
                    index += 1
                else:
                    dict_str = dict_str + data[x]
            self.data_queue.append(dict_str)


def main():
    print("=== Code Nexus - Data Processor ===")

    print("\nTesting Numeric Processor...")
    numbers = NumericProcessor()
    print(" Trying to validate input '42':", end=" ")
    valid = numbers.validate(42)
    print(f"{valid}")
    print(" Trying to validate input 'Hello':", end=" ")
    valid = numbers.validate("Hello")
    print(f"{valid}")
    print(" Test invalid ingestion of string 'foo' without prior validation:")
    """
    try:
        numbers.ingest("foo")
    except Exception as e:
        print(f" Got exception: {e}")
    """
    print(" Processing data: [1, 2, 3, 4, 5]")
    numbers.ingest([1, 2, 3, 4, 5])
    print(" Extracting 3 values...")
    data = numbers.output()
    print(f" Numeric value {data[0]}: {data[1]}")
    data = numbers.output()
    print(f" Numeric value {data[0]}: {data[1]}")
    data = numbers.output()
    print(f" Numeric value {data[0]}: {data[1]}")

    print("\nTesting Text Processor...")
    text = TextProcessor()
    print(" Trying to validate input '42':", end=" ")
    valid = text.validate(42)
    print(f"{valid}")
    print(" Processig data: ['Hello', 'Nexus', 'World']")
    text.ingest(['Hello', 'Nexus', 'World'])
    print(" Extracting 1 value...")
    data = text.output()
    print(f" Text value {data[0]}: {data[1]}")

    print("\nTesting Log Processor...")
    log = LogProcessor()
    print(" Trying to validate input 'Hello':", end=" ")
    valid = log.validate('Hello')
    print(f"{valid}")
    print(
        " Processing data: [{'log_level': 'NOTICE',"
        " 'log_message': 'Connection to server'}, "
        "{'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]")
    print(" Extracting 2 values")
    log.ingest([
        {
            'log_level': 'NOTICE',
            'log_message': 'Connection to server'
        },
        {
            'log_level': 'ERROR',
            'log_message': 'Unauthorized access!!'
        }
    ])
    data = log.output()
    print(f" Log entry {data[0]}: {data[1]}")
    data = log.output()
    print(f" Log entry {data[0]}: {data[1]}")


if __name__ == "__main__":
    main()
