from tkinter import font
from PIL import Image, ImageTk
import tkinter as tk
from modules.gui.fluiddiagramframe import LampLabel
# left


class CountdownFrame(tk.LabelFrame):
    def __init__(self, master: tk.Tk):
        super().__init__(master, text='Countdown')
        self.countdown_label = tk.Label(
            master=self, text='T-00:10.00', font=font.Font(size=40), anchor='center')
        self.countdown_label.grid()


class MajorControlsFrame(tk.LabelFrame):
    def __init__(self, master: tk.Tk):
        super().__init__(master, text='Major controls')
        self.abort_button = tk.Button(
            self, text='ABORT', font=font.Font(size=20))
        self.proceed_button = tk.Button(
            self, text='PROCEED', font=font.Font(size=20))
        self.abort_button.grid()
        self.proceed_button.grid(row=0, column=2)


class ChecklistFrame(tk.LabelFrame):
    def __init__(self, master: tk.Tk):
        super().__init__(master, text='Checklist')


class StateInfoFrame(tk.LabelFrame):
    def __init__(self, master: tk.Tk):
        super().__init__(master, text='State Info')
        self.state_label = tk.Label(
            self, text='Current: blah\nProceed: blah...........\nAbort: asdfasdf asdf', justify='left')
        self.state_label.grid()


class EngineComputerStatusFrame(tk.LabelFrame):
    def __init__(self, master: tk.Tk):
        super().__init__(master, text='Engine Computer Status')
        self.telem_label = LampLabel(
            self, text='Telemetry (heartbeat 234ms ago)')
        self.power_label = LampLabel(
            self, text='Power (12.3V, Internal)')
        self.telem_label.grid(sticky='w')
        self.power_label.grid(row=1, column=0, sticky='w')


class DataloggingFrame(tk.LabelFrame):
    def __init__(self, master: tk.Tk):
        super().__init__(master, text='Datalogging')
        self.logging_label = tk.Label(
            self, text='Logging to 2020.12.17-16:36-GROUND.log')
        self.onboard_button = tk.Button(self, text='Downlink Onboard Data')
        self.logging_label.grid()
        self.onboard_button.grid(row=0, column=1)
