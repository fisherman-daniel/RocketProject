# # config_parser.py
# # Henry Nester
# # 19 March 2021

# # Parser for .yaml files containing design data

# import yaml
# import pint


# def parse_input(filename: str) -> dict:
#     return add_units(open(filename, 'r'))


# def add_units(data: dict) -> dict:
#     '''Takes a dictionary (can be nested) containing design data and converts all measurement strings (e.g. 100km/s, 12.3bar, etc.) to pint Quantity objects. Returns the new dictionary'''
#     data_t = type(data)
#     if data_t == dict:
#         for key in data:
#             data[key] = add_units(data[key])
#     elif data_t == list:
#         data = [add_units(element) for element in data]
#     else:
#         try:
#             if str(data)[0].isnumeric():
#                 data = pint.Quantity(data)
#         except pint.UndefinedUnitError:
#             pass
#     return data
