from abc import ABC, abstractmethod
from . import creatures


class CreateFactory(ABC):

    @abstractmethod
    def create_base(self):
        pass

    @abstractmethod
    def create_evolved(self):
        pass

class FlameFactory(CreatureFactory):
    def create_base(self):
        return Flameling()

    def create_envolved(self):
