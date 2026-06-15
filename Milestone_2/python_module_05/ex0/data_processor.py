import typing
import ABC


class DataProcessor(ABC) -> None:

    def validate(self, data: Any) -> bool:

    def ingest(self, data: Any) -> None:

    def output(self) -> tuple[int, str]:

class NumericProcessor(DataProcessor)


class TextProcessor(DataProcessor)


class LogProcessor(DataProcessor)



