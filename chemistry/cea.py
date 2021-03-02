# cea.py
# Henry Nester
# 1 March 2021 (based on the old MATLAB program from Nov. '20)

# Program to interface with NASA's CEA (Chem. Eqbr. w/ Appns.) program
# Basically creates a .inp file to CEA's spec, runs CEA.exe, which creates a .out file
# Parses .out file to get data we want

# CEA has a bunch of other options besides what this program does
# peek the manual at http://akrmys.com/public/cea/doc/xRP-1311P2.pdf if you hate urself

import subprocess
import csv
import numpy as np

CEA_EXE = 'FCEA2m.exe'
CEA_ARG = 'ceaarg.txt'
CEA_FILENAME = 'ceadata'
INPUT_FILE = CEA_FILENAME+'.inp'
OUTPUT_FILE = CEA_FILENAME+'.csv'


def create_CEA_inp_file(fuel_chemical, fuel_temp_initial, oxidiser_chemical, oxidiser_temp_initial, chamber_pressure, chamber_ambient_pressure_ratio,
                        oxidiser_fuel_mass_ratio, do_equilibrium_calc=True):
    # do all fileops in the with to allow file to close afterward
    with open(INPUT_FILE, mode='w', newline='\n') as f:
        # idk if the newlines are needed but they make the inp file readable
        f.write('problem\n')
        f.write('rocket\n')
        if do_equilibrium_calc:
            # this option assumes all rxn occuring during nozzle expansion have infinite rxn rate
            # slightly underestimates engine performance
            f.write('equilibrium\n')

        # parameters for problem
        f.write(f'p,bar={chamber_pressure}\n')
        f.write(f'pip={chamber_ambient_pressure_ratio}\n')
        f.write(f'o/f={oxidiser_fuel_mass_ratio}\n')

        # specify reactants (fuel/ox)
        f.write('react\n')
        # wt can be used if we dilute the fuel or oxidiser
        # eg if we use compressed air instead of GOX
        f.write(f'fuel={fuel_chemical} wt=100 T,K={fuel_temp_initial}\n')
        f.write(
            f'ox={oxidiser_chemical} wt=100 T,K={oxidiser_temp_initial}\n')

        # specify how we want the output data - in a csv file
        f.write('output\n')
        f.write('plot o/f t isp\n')

        f.write('end')  # last thing in the file. required!


def run_CEA():
    # FCEA2m.exe is *special*
    # it takes no cmd line arguments, but when you run it it expects you to type something in
    # namely, the name of the input file, without the .inp ext.

    # this method will make the program crash if there are any issues running the command line
    subprocess.run([CEA_EXE],  input=CEA_FILENAME+'\n',
                   encoding='ascii', stdout=subprocess.DEVNULL, check=True)


def read_CEA_outfile():
    with open(OUTPUT_FILE, 'r') as f:
        data = csv.reader(f, delimiter=',')
        next(data)  # skip first row (headers)
        chamber_temp = float(next(data)[1])
        throat_temp = float(next(data)[1])
        _, exit_temp, isp = (float(x) for x in next(data))
        return ((chamber_temp, throat_temp, exit_temp), isp)


def run_CEA_over_range(mixture_ratios, chamber_pressures, ambient_pressure=1.013):
    print('Starting CEA calculations')
    data = []
    for pcham in chamber_pressures:
        row = []
        for mix in mixture_ratios:
            create_CEA_inp_file('JP-5', 298, 'O2', 298,
                                pcham, pcham / ambient_pressure, mix)
            run_CEA()
            result = read_CEA_outfile()
            row.append(tuple((mix, read_CEA_outfile())))
        data.append(tuple((pcham, row)))
    print('CEA calculations done')
    return data
