from lib import cea, nozzle
import sys
import os
import yaml
import numpy as np
import json


def main():
    data = yaml.safe_load(open('design_data.yaml', 'r'))

    cea.create_inp_file(data)
    cea.run_executable()
    cea.parse_out_file(data)

    nozzle.calculate_nozzle_parameters(data)

    yaml.dump(data, open('output_design_data.yaml', 'w'))


if __name__ == '__main__':
    main()
