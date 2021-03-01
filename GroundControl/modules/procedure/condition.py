from enum import Enum


class ManualAutoType(Enum):
    MANUAL = 1,
    MANUAL_AUTO_ASSIST = 2,
    AUTO = 3


class Condition:
    def __init__(self, name, eval_func=None, check_off_type=ManualAutoType.MANUAL):
        self.name = name
        self.pretty_name = pretty_name
        self.eval_func = eval_func
        self.check_off_type = check_off_type
