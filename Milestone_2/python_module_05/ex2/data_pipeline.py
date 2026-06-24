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


class ExportPlugin(typing.Protocol):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


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
                f"{type(proc).__name__.replace('Processor', ' Processor')}: "
                f"total {proc._rank} items processed, "
                f"remaining {len(proc._data)} on processor"
            )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self._processors:
            output_data: list[tuple[int, str]] = []

            for _ in range(nb):
                try:
                    output_data.append(proc.output())
                except Exception:
                    break
            if output_data:
                plugin.process_output(output_data)


class CSVPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        values: list[str] = []

        for item in data:
            values.append(item[1])

        print("CSV Output:")
        print(",".join(values))


class JSONPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        items: list[str] = []

        for item in data:
            rank = item[0]
            value = item[1]
            items.append(f'"item_{rank}": "{value}"')

        print("JSON Output:")
        print("{" + ", ".join(items) + "}")


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===\n")

    print("Initialize Data Stream...\n")
    stream = DataStream()
    stream.print_processors_stats()

    print("\nRegistering Processors\n")
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    stream.register_processor(numeric)
    stream.register_processor(text)
    stream.register_processor(log)

    data = ['Hello world', [3.14, -1, 2.71],
            [{'log_level': 'WARNING',
              'log_message': 'Telnet access! Use ssh instead'},
             {'log_level': 'INFO',
              'log_message': 'User wil is connected'}], 42, ['Hi', 'five']]

    stream.process_stream(data)
    stream.print_processors_stats()

    print("\nSend 3 processed data from each processor to a CSV plugin:")
    csv = CSVPlugin()
    stream.output_pipeline(3, csv)
    stream.print_processors_stats()

    print("\nSend another batch of data: ", end="")
    data = [21, ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
            [{'log_level': 'ERROR', 'log_message': '500 server crash'},
            {'log_level': 'NOTICE',
             'log_message': 'Certificate expires in 10 days'}],
            [32, 42, 64, 84, 128, 168], 'World hello']
    print(data)

    stream.process_stream(data)
    stream.print_processors_stats()

    print("\nSend another 5 processed data to a JSON plugin:")
    json = JSONPlugin()
    stream.output_pipeline(5, json)
    stream.print_processors_stats()


if __name__ == "__main__":
    main()
