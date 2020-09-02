import csv

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

def ecart_type(variance):
    return variance ** 0.5

def variance(data):
    avg = average(data['km'])
    den = 0
    num = 0

    for km, price in zip(data['km'], data['price']):
        den += price * (km - avg) ** 2
        num += price
    return den / num

def normalize_data(data):
    tmp_price = []
    tmp_km    = []
    km_avg    = average(data['km'])
    price_avg = average(data['price'])
    e_t       = ecart_type(variance(data))

    for km, price in zip(data['km'], data['price']):
        tmp_km.append((km - km_avg) / e_t)
        tmp_price.append((price - price_avg) / e_t)
    data['km']    = tmp_km
    data['price'] = tmp_price
    return data

def mean_normalization(liste):
	liste2 = []
	for x in range(len(liste)):
		liste2.append(liste[x] / max(liste))
	return(liste2)

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