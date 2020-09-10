import csv
import matplotlib.pyplot as plt

def average(collection):
    v = 0

    for elem in collection:
        v += elem
    return v / len(collection)

def print_error(str, mode, c1, c2, c3):
    print(c1 + c2 + '\033[91merror:\033[0m ' + str + c3)
    if mode == 1:
        exit(0)

def convert_to_number(str):
    try:
        try:
            return int(str)
        except ValueError:
            return float(str)
    except ValueError:
        print_error("Elems of 'data.csv' are supposed to be numbers.", 1, '\n', '\t', '\n')

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
                print_error("Rows names of 'data.csv' are supposed to be 'km' and 'price'.", 1, '\n', '\t', '\n')
            for elem in file:
                data['km'].append(convert_to_number(elem['km']))
                data['price'].append(convert_to_number(elem['price']))
            if not data['km']:
                print_error("There are no data in 'data.csv'.", 1, '\n', '\t', '\n')
        data['m'] = len(data['km'])
        return data
    except FileNotFoundError as e:
        print_error(str(e), 1, '\n', '\t', '\n')

def write_thetas(t0, t1):
    try:
        file = open('thetasValue.txt','w')
        file.write(str(t0) + '|' + str(t1))
        file.close()
    except FileNotFoundError as e:
        print_error(str(e), 1, '\n', '\t', '\n')
