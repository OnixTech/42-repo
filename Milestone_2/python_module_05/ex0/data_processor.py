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
        self._rank += 1
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
        else:
            self._data.append(str(data))


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
        else:
            self._data.append(data)


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
        else:
            values = list(data.values())
            self._data.append(values[0] + ": " + values[1])


def main() -> None:
    print("=== Code Nexus - Data Processor ===")

    print("Testing Numeric processor...")
    numeric = NumericProcessor()
    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(f"Trying to validate input 'Hello': {numeric.validate('Hello')}")

    print("Test invalid ingestion of string 'foo' without prior validation")
    try:
        numeric.ingest("foo")
    except Exception as err:
        print(f"Got exception: {err}")

    print("Processing data: [1, 2, 3, 4, 5]")
    numbers: list[int | float] = [1, 2, 3, 4, 5]
    numeric.ingest(numbers)
    print("Extracting 3 values")
    for _ in range(3):
        num_o = numeric.output()
        print(f"Numeric value {num_o[0]}: {num_o[1]}")

    print("Testing Text Processor...")
    text = TextProcessor()
    print(f"Trying to validate input '42': {text.validate(42)}")
    words = ['Hello', 'Nexus', 'World']
    print(f"Processing data: {words}")
    text.ingest(words)
    print("Extracting 1 value...")
    text_o = text.output()
    print(f"Text value {text_o[0]}: {text_o[1]}")

    print("Testing Log Processor...")
    log = LogProcessor()
    print(f"Trying to validate input 'Hello': {log.validate('Hello')}")
    logs = [{"log_level": "NOTICE", "log_message": "Connection to server"},
            {"log_level": "ERROR", "log_message": "Unauthorized access!!"}]
    print(f"Processing data: {logs}")
    log.ingest(logs)
    print("Extracting 2 values...")
    log_o = log.output()
    level = log_o[0]
    message = log_o[1]
    print(f"Log entry {level}: {message}")
    log_o1 = log.output()
    level = log_o1[0]
    message = log_o1[1]
    print(f"Log entry {level}: {message}")


if __name__ == "__main__":
    main()
