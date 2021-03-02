# cea_plotgen.py
# Henry Nester
# 2 March 2021

# script to plot chamber temperature and specific impulse curves vs. mixture ratio and chamber pressures
# employs cea.py interface module to NASA CEA program

# plot is saved as plotoutput.png as well as displayed on screen

import cea

import numpy as np

# range of of ratios to get data over
mixture_ratios = np.linspace(1, 3, 10)
# range of pressures to get data over
chamber_pressures = np.linspace(10, 30, 5)


def plotter(table, show=True, save=True):
    import matplotlib.pyplot as plt
    fig = plt.figure(1)
    fig.suptitle('Rocket Combustion of JP-5 & GOX, T0=298K, Pamb=1atm')
    axL = fig.add_subplot(1, 2, 1)
    axR = fig.add_subplot(1, 2, 2)
    axL.set_xlabel('O/F ratio (kg/kg)')
    axL.set_ylabel('Isp (m/s)')
    axR.set_xlabel('O/F ratio (kg/kg)')
    axR.set_ylabel('Tcham (K)')
    pcham_max = max([t[0] for t in data])
    for pcham, mixes_vals in data:
        mixes, vals = zip(*mixes_vals)
        temps = [t[0][0] for t in vals]
        isps = [t[1] for t in vals]
        linecolor = (pcham / pcham_max, 1 - pcham / pcham_max, 0)
        axL.plot(mixes, isps, color=linecolor, label=pcham)
        axR.plot(mixes, temps, color=linecolor, label=pcham)
    axR.legend(title='Pcham (bar)')
    fig.tight_layout()  # stops margin overlap
    if save:
        plt.savefig(fname='plotoutput', bbox_inches='tight')
    if show:
        plt.show()


# range of of ratios to get data over
mixture_ratios = np.linspace(1, 3, 10)
# range of pressures to get data over
chamber_pressures = np.linspace(10, 30, 5)

data = cea.run_CEA_over_range(mixture_ratios, chamber_pressures)
plotter(data)
