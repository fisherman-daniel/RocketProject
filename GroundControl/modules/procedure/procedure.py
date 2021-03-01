import json
from enum import Enum


class ManualAutoType(Enum):
    MANUAL = 1,
    MANUAL_AUTO_ASSIST = 2,
    AUTO = 3


class Procedure:
    def __init__(self, name, steps, abort_procedure=None, abort_conditions=[]):
        self.name = name
        self.steps = steps
        self.abort_procedure = abort_procedure
        self.abort_conditions = abort_conditions

        self.current_step_idx = 0  # start from first step

    def next_step(self):
        next_step()

# fuelstate = State("fuel")
# oxstate = State("ox")
# preflightstate = State("preflight", substates=[fuelstate, oxstate])

# with open('test.json', 'w') as outfile:
#     json.dump(preflightstate.__dict__, outfile,
#               default=lambda x: x.__dict__, indent=4)

# print('done')


class ProcedureStep:
    def __init__(self, name, auto_type=ManualAutoType.MANUAL):
        self.name = name
        self.auto_type = auto_type

    def perform(self):
        raise NotImplementedError()


class Condition(ProcedureStep):
    def __init__(self, name, eval_func=None):
        super().__init__(name)
        self.eval_func = eval_func


class Action(ProcedureStep):
    def __init__(self, name, func=None):
        super().__init__(name)
        self.func = func

    # returns
    def perform(self):
        self.func()
