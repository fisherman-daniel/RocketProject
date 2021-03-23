from lib import cea, nozzle
import sys
import os
import yaml
import numpy as np
import shutil


def main():
    # filepaths nonsense
    DATAPATH = './data'
    INFILE, OUTFILE = os.path.join(DATAPATH, 'design_data.yaml'), os.path.join(
        DATAPATH, 'output_design_data.yaml')

    # load design parameters input
    print('Propulsion Design Script')
    print(f'Loading design parameters from {INFILE}')
    data = yaml.safe_load(open(INFILE, 'r'))

    # run CEA to get propellant combustion data
    print('Generating CEA .inp file')
    cea_inp_path = cea.create_inp_file(data)
    print('Running CEA executable')
    cea_out_path = cea.run_executable()
    print('Parsing CEA .out file')
    cea.parse_out_file(data)
    print(f'Copying CEA files to {DATAPATH}')
    shutil.copy(cea_inp_path, DATAPATH)
    shutil.copy(cea_out_path, DATAPATH)

    # calculate nozzle/engine dimensions, etc.
    nozzle.calculate_nozzle_parameters(data)

    # save all design parameters (input & calculated outputs)
    print(f'Writing design parameters to {OUTFILE}')
    yaml.dump(data, open(OUTFILE, 'w'))


if __name__ == '__main__':
    main()
