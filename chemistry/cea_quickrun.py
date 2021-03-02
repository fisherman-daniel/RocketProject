import cea

pcham = float(input('Chamber pressure (bar): '))
mix = float(input('Ox/fuel ratio (kg/kg): '))
pamb = 1.013

cea.create_CEA_inp_file('JP-5', 298, 'O2', 298, pcham, pcham/pamb, mix)
cea.run_CEA()

result = cea.read_CEA_outfile()

print(
    f'Temperatures (K)\nChamber: {result[0][0]}\nThroat: \
        {result[0][1]}\n Exit: {result[0][2]}')
print(f'Specific impulse (m/s): {result[1]}')
