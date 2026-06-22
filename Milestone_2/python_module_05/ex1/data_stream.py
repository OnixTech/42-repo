import typing
import abc


class DataProcessor(abc.ABC):

    def __init__(self) -> None:
        self._data: list[str] = []
        self._rank: int = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if len(self._data) == 0:
            raise Exception("No data to output")

        value = self._data[0]
        self._data.pop(0)
        rank = self._rank
        return (rank, value)


class NumericProcessor(DataProcessor):

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, int) or isinstance(data, float):
            return True

        if isinstance(data, list):
            for item in data:
                if not isinstance(item, int) and not isinstance(item, float):
                    return False
            return True

        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise Exception("Improper numeric data")

        if isinstance(data, list):
            for item in data:
                self._data.append(str(item))
                self._rank += 1
        else:
            self._data.append(str(data))
            self._rank += 1


class TextProcessor(DataProcessor):

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True

        if isinstance(data, list):
            for item in data:
                if not isinstance(item, str):
                    return False
            return True

        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise Exception("Improper text data")

        if isinstance(data, list):
            for item in data:
                self._data.append(item)
                self._rank += 1
        else:
            self._data.append(data)
            self._rank += 1


class LogProcessor(DataProcessor):

    def validate(self, data: typing.Any) -> bool:
        if self._is_dict(data):
            return True

        if isinstance(data, list):
            for item in data:
                if not self._is_dict(item):
                    return False
            return True

        return False

    def _is_dict(self, data: typing.Any) -> bool:
        if not isinstance(data, dict):
            return False

        for key, value in data.items():
            if not isinstance(key, str):
                return False

            if not isinstance(value, str):
                return False

        return True

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise Exception("Improper log data")

        if isinstance(data, list):
            for item in data:
                values = list(item.values())
                self._data.append(values[0] + ": " + values[1])
                self._rank += 1
        else:
            values = list(data.values())
            self._data.append(values[0] + ": " + values[1])
            self._rank += 1


class DataStream:

    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for element in stream:
            processed = False

            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    processed = True
                    break

            if not processed:
                print("DataStream error - Can't process element", end="")
                print(f" in stream: {element}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if not self._processors:
            print("No processor found, no data")
            return

        for proc in self._processors:
            print(
                f"{type(proc).__name__.replace("Processor", " Processor")}: "
                f"total {proc._rank} items processed, "
                f"remaining {len(proc._data)} on processor"
            )


def main() -> None:
    print("=== Code Nexus - Data Stream ===")

    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()

    print("\nRegistering Numeric Processor")
    numeric = NumericProcessor()
    stream.register_processor(numeric)

    data = ['Hello world', [3.14, -1, 2.71],
            [{'log_level': 'WARNING',
              'log_message': 'Telnet access! Use ssh instead'},
             {'log_level': 'INFO',
              'log_message': 'User wil is connected'}], 42, ['Hi', 'five']]

    print(f"\nSend first batch of data on stream: {data}")
    stream.process_stream(data)

    stream.print_processors_stats()

    print("\nRegistering other data processors")
    text = TextProcessor()
    log = LogProcessor()
    stream.register_processor(text)
    stream.register_processor(log)
    print("Send the same batch again")
    stream.process_stream(data)
    stream.print_processors_stats()

    print("Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    numeric.output()
    numeric.output()
    numeric.output()

    text.output()
    text.output()

    log.output()

    stream.print_processors_stats()


if __name__ == "__main__":
    main()
