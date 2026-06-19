import typing
import abc


class DataProcessor(abc.ABC):

    def __init__(self, data=None):
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
        if self.validate(data) == False:
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

    def ingest(self, data: str | list[str]) -> None:
        if self.validate(data) == False:
            raise Exception("Improper text data")

        if isinstance(data, list):
            for item in data:
                self._data.append(item)
        else:
            self._data.append(data)

class LogProcessor(DataProcessor):

    def validate(self, data: typing.Any) -> bool:
        if _is_dict(data):
            return True        

        if isinstance(data, list):
            for item in data:
               if not _is_dict(item):
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

    def ingest(self, data: dict[str:str] | list[dict[str : str]]) -> None:
        if not self.validate(data):
            raise Exception("Improper log data")

        if isinstance(data, list):
            for item in data:
                self._data.append(str(item))
        else:
            self._data.append(str(data))


def main() -> None:
    print("=== Code Nexus - Data Processor ===")

    print("Testing Numeric processor...")
    numeric = NumericProcessor()
    print(f"Testing valid input '42': {numeric.validate(42)}")


if __name__ == "__main__":
    main()
