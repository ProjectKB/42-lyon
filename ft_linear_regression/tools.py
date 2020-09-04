import csv
import matplotlib.pyplot as plt

def average(collection):
    v = 0

    for elem in collection:
        v += elem
    return v / len(collection)

def print_error(str):
    print('error: \033[91m' + str + '\033[0m')
    exit(0)

def convert_to_number(str):
    try:
        try:
            return int(str)
        except ValueError:
            return float(str)
    except ValueError:
        print_error('Elems are supposed to be numbers.')

def sum(t0, t1, data, operation):
    v = 0

    for km, price in zip(data['km'], data['price']):
        v += operation(km, price)
    return v

def parse_csv():
    try:
        with open('data.csv', newline='') as csvfile:
            file = csv.DictReader(csvfile)
            data = {
                'km':    [],
                'price': []
            }

            if file.fieldnames != ['km', 'price']:
                print_error("Rows names are supposed to be 'km' and 'price'.")
            for elem in file:
                data['km'].append(convert_to_number(elem['km']))
                data['price'].append(convert_to_number(elem['price']))
            if not data['km']:
                print_error("There are no data.")
        data['m'] = len(data['km'])
        return data
    except FileNotFoundError as e:
        print_error(str(e))


