import tkinter as tk
from modules.gui.subframes import *
from modules.gui.fluiddiagramframe import FluidDiagramFrame


class MainWindow():
    @classmethod
    def start(cls):
        master = tk.Tk()
        cls.master = master
        # window setup
        master.title("Mission Control")
        master.wm_attributes('-fullscreen', True)

        # left,center divisions
        master.rowconfigure(0, weight=1)
        master.columnconfigure(1, weight=1)

        left = tk.Frame(master)
        left.grid(row=0, column=0, sticky='nsew')

        center = tk.Frame(master)
        center.grid(row=0, column=1, sticky='nsew')

        # left division has countdown, arm/abort controls, and checklist
        left.rowconfigure(0, weight=1)
        checkList = ChecklistFrame(left)
        checkList.grid(row=0, column=0, sticky='nsew')
        countdown = CountdownFrame(left)
        countdown.grid(row=1, column=0, sticky='nsew')
        majorControls = MajorControlsFrame(left)
        majorControls.grid(row=2, column=0, sticky='nsew')

        # center division has plumbing diagram, state log, and engine computer status
        center.rowconfigure(0, weight=1)
        center.columnconfigure(2, weight=1)
        fluidDiagram = FluidDiagramFrame(center)
        fluidDiagram.grid(row=0, column=0, columnspan=3, sticky='nsew')
        stateInfo = StateInfoFrame(center)
        stateInfo.grid(row=1, column=0, sticky='nsew')
        engineComputerStatus = EngineComputerStatusFrame(center)
        engineComputerStatus.grid(row=1, column=1, sticky='nsew')
        datalogging = DataloggingFrame(center)
        datalogging.grid(row=1, column=2, sticky='nsew')

        # infinite loop for GUI
        master.mainloop()
