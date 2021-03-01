from PIL import Image, ImageTk
import tkinter as tk


class FluidDiagramFrame(tk.LabelFrame):
    def __init__(self, master: tk.Tk):
        super().__init__(master, text='Fluid Diagram')
        self.img = ImageTk.PhotoImage(Image.open(
            'modules/gui/rocket.png'))
        self.img_label = tk.Label(self, image=self.img, width=800, height=800)
        self.img_label.grid(rowspan=3, columnspan=3)
        self.valve = ValveFrame(self)
        self.press = PressureFrame(self)
        self.ign = IgnitorFrame(self)
        self.fill = FillLinesFrame(self)
        self.thrust = LoadCellFrame(self)
        self.valve.grid(row=0, column=0)
        self.press.grid(row=0, column=1)
        self.ign.grid(row=0, column=2)
        self.fill.grid(row=0, column=3)
        self.thrust.grid(row=0, column=4)


class PressureFrame(tk.Frame):
    def __init__(self, master: tk.Tk):
        super().__init__(master)
        self.setup()

    def setup(self):
        # title
        self.title_label = tk.Label(self, text='FUEL TANK PRESSURE')
        self.pressure_label = LampLabel(self, text='123.4bar')

        self.title_label.grid()
        self.pressure_label.grid(row=1, column=0, sticky='w')


class IgnitorFrame(tk.Frame):
    def __init__(self, master: tk.Tk):
        super().__init__(master)
        self.setup()

    def setup(self):
        # title
        self.title_label = tk.Label(self, text='IGNITOR')
        self.cont_label = LampLabel(self, text='Continuity')
        self.firing_label = LampLabel(self, text='Firing')

        self.title_label.grid()
        self.cont_label.grid(row=1, column=0, sticky='w')
        self.firing_label.grid(row=2, column=0, sticky='w')


class LoadCellFrame(tk.Frame):
    def __init__(self, master: tk.Tk):
        super().__init__(master)
        self.setup()

    def setup(self):
        # title
        self.title_label = tk.Label(self, text='LOAD CELL\nTHRUST')
        self.thrust_label = LampLabel(self, text='123.4N')

        self.title_label.grid()
        self.thrust_label.grid(row=1, column=0, sticky='w')


class FillLinesFrame(tk.Frame):
    def __init__(self, master: tk.Tk):
        super().__init__(master)
        self.setup()

    def setup(self):
        # title
        self.title_label = tk.Label(self, text='FILL LINES\nCONNECTED')
        self.cont_label = LampLabel(self, text='Fuel')
        self.firing_label = LampLabel(self, text='Oxidiser')

        self.title_label.grid()
        self.cont_label.grid(row=1, column=0, sticky='w')
        self.firing_label.grid(row=2, column=0, sticky='w')


class ValveFrame(tk.Frame):
    def __init__(self, master: tk.Tk):
        super().__init__(master)
        self.setup()

    def setup(self):
        # title
        self.title_label = tk.Label(self, text='MAIN FUEL VALVE')
        # indicator lamps for state
        self.encoder_label = LampLabel(self, text='Encoder')
        self.open_label = LampLabel(self, text='Open')
        self.closed_label = LampLabel(self, text='Closed')
        self.manual_label = LampLabel(self, text='Manual')
        self.auto_label = LampLabel(self, text='Auto')
        self.pos_display = tk.Canvas(self, width=60, height=20)
        self.power_display = tk.Canvas(self, width=60, height=2)
        self.open_button = tk.Button(self, text='Open')
        self.close_button = tk.Button(self, text='Close')
        self.set_pos_button = tk.Button(self, text='Set position')
        self.set_pos_spinbox = tk.Spinbox(
            self, from_=0, to=100, increment=5, state='readonly', width=3)
        self.pulse_button = tk.Button(self, text='Pulse open')
        self.pulse_spinbox = tk.Spinbox(
            self, from_=10, to=200, increment=10, state='readonly', width=3)
        self.manual_button = tk.Button(self, text='Release manual override')

        self.pos_display.create_rectangle(
            0, 0, 50, 20, fill='green', outline='')
        self.pos_display.create_polygon(
            43, 20, 57, 20, 50, 12, fill='red', outline='', width=0)

        self.power_display.create_rectangle(
            0, 0, 20, 5, fill='red', outline='')

        self.title_label.grid(row=0, columnspan=2)
        self.encoder_label.grid(row=1, sticky='w')
        self.open_label.grid(row=2, sticky='w')
        self.closed_label.grid(row=2, column=1, sticky='w')
        self.manual_label.grid(row=3, column=0, sticky='w')
        self.auto_label.grid(row=3, column=1, sticky='w')
        self.pos_display.grid(row=4, columnspan=2, sticky='ew')
        self.power_display.grid(row=5, columnspan=2, sticky='ew')
        self.open_button.grid(row=6, sticky='w')
        self.close_button.grid(row=6, column=1, sticky='w')
        self.set_pos_button.grid(row=7, sticky='w')
        self.set_pos_spinbox.grid(row=7, column=1, sticky='w')
        self.pulse_button.grid(row=8, sticky='w')
        self.pulse_spinbox.grid(row=8, column=1, sticky='w')
        self.manual_button.grid(row=9, columnspan=2, sticky='w')

        # self.command_button.grid(row=4, columnspan=2, stick='nsew')
        # position indicator
        # motor power level indicator


class LampLabel(tk.Frame):
    def __init__(self, master: tk.Tk, text: str):
        super().__init__(master)
        self.label = tk.Label(self, text=text)
        self.lamp_label = tk.Label(
            self, text='\u2B24', foreground='red')  # big bullet point character is a "lamp"
        self.lamp_label.grid()
        self.label.grid(row=0, column=1)

    def set_lamp(self, color: str):
        self.lamp_label.foreground = color
        pass
        # self.img = imgDict[color]
        # self.lamp_label.configure(image=self.img)
