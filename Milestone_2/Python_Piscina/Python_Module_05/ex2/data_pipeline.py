from typing import Any, Protocol
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.data_queue: list[Any] = []
        self.data_rank: int = -1
        self.outputted: int = 0
        self.items_processed: int = 0

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
        self.outputted += 1
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
            self.items_processed += len(data)
        else:
            self.data_queue.append(str(data))
            self.items_processed += 1


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
            self.items_processed += len(data)
        else:
            self.data_queue.append(data)
            self.items_processed += 1


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
            self.items_processed += len(data)
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
            self.items_processed += 1


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class DataStream:
    def __init__(self):
        self.processors = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for data in stream:
            found = False
            for proc in self.processors:
                if proc.validate(data):
                    proc.ingest(data)
                    found = True
                    break
            if not found:
                print(
                    "DataStream error"
                    f" - Can't procecss element in stream: {data}")

    def print_processors_stats(self) -> None:
        if len(self.processors) == 0:
            print("No processor found, no data")
        else:
            for proc in self.processors:
                if isinstance(proc, NumericProcessor):
                    print("Numeric Processor:", end=" ")
                elif isinstance(proc, TextProcessor):
                    print("Text Processor:", end=" ")
                elif isinstance(proc, LogProcessor):
                    print("Log Processor:", end=" ")
                print(
                    f"total {proc.items_processed} items processed,", end=" ")
                print(
                    f"remaining {proc.items_processed - proc.outputted} on"
                    " processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:

        outputs: list[list[tuple[int, str]]] = [[]]
        for x in range(len(self.processors) - 1):
            outputs.append([])

        index = 0
        for proc in self.processors:
            for x in range(nb):
                outputs[index].append(proc.output())
            index += 1
        index = 0
        for proc in self.processors:
            plugin.process_output(outputs[index][:nb])
            index += 1


class CSVPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        index = 0
        print("CSV Output:")
        valid = [x for x in data if x[1] != ""]
        for x in valid:
            if index < (len(valid) - 1):
                print(f"{x[1]}", end=",")
                index += 1
            else:
                print(f"{x[1]}")


class JSONPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        index = 0
        print("JSON Output:")
        valid = [x for x in data if x[1] != ""]
        print("{", end="")
        for x in valid:
            if index < (len(valid) - 1):
                print(f"\"item_{x[0]}\": \"{x[1]}\"", end=", ")
                index += 1
            else:
                print(f"\"item_{x[0]}\": \"{x[1]}\"", end="")
        print("}")


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")

    print("\nInitialize Data Stream...")
    data = DataStream()

    print("\n== DataStream statistics ==")
    data.print_processors_stats()

    print("\nRegistering Processors")
    number = NumericProcessor()
    data.register_processor(number)
    text = TextProcessor()
    data.register_processor(text)
    log = LogProcessor()
    data.register_processor(log)

    print(
        "\nSend first batch of data on stream: ['Hello world', [3.14, -1, 2.71"
        ", [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh "
        "instead'}, {'log_level': 'INFO', 'log_message': 'User wi is connected"
        "'}], 42, ['Hi', 'five']]")
    data.process_stream([
        'Hello world',
        [3.14, -1, 2.71],
        [
            {
                'log_level': 'WARNING',
                'log_message': 'Telnet access! Use ssh instead'
            },
            {
                'log_level': 'INFO',
                'log_message': 'User wil is connected'
            }
        ],
        42,
        ['Hi', 'five']
    ])

    print("\n== DataStream statistics ==")
    data.print_processors_stats()

    print("\nSend 3 processed data from each processor to a CSV plugin:")
    csv = CSVPlugin()
    data.output_pipeline(3, csv)

    print("\n== DataStream statistics ==")
    data.print_processors_stats()

    print(
        "\nSend another batch of data: [21, ['I love AI', 'LLMs are wonderful'"
        ", 'Stay healthy'], [{'fog_level': 'ERROR', 'log_message': '500 server"
        " crash'}, {'log_level': 'NOTICE', 'log_message': 'Certificate expires"
        " in 10 days'}], [32, 42, 64, 84, 128, 168], 'World hello]'")
    data.process_stream([
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {
                'fog_level': 'ERROR',
                'log_message': '500 server crash'
            },
            {
                'log_level': 'NOTICE',
                'log_message': 'Certificate expires in 10 days'
            }
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ])
    print("\n== DataStream statistics ==")
    data.print_processors_stats()

    print("Send 5 processed data from each processor to a JSON plugin:")
    json = JSONPlugin()
    data.output_pipeline(5, json)

    print("\n== DataStream statistics ==")
    data.print_processors_stats()


if __name__ == "__main__":
    main()
