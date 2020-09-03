import re
import tools

def check(args, checker, elem_nb):
    check = 0
    base = len(args)
    case1       = re.findall(r'-?\d*\.?\d*\*X\^-?\d*\.?\d+=-?\d*\.?\d*\*X\^-?\d*\.?\d+', args)
    case2       = re.findall(r'-?\d*\.?\d*\*X\^-?\d*\.?\d+=0', args)

    if case1:
        check += 1 + (elem_nb - 2)
    elif case2:
        check += 2 + (elem_nb - 1)
    else:
        tools.print_and_quit('Bad expression')

    if args[0] == '-':
        check += 1
    check += len(checker)

    #print('check:', check)
    #print('base:', base)
    #exit(0)


def extract_data(args, original_entry):
    data = {
        'left_side': {
            'degrees': [],
            'numbers': []
        },
        'right_side': {
            'degrees': [],
            'numbers': []
        }
    }
    checker = ""
    nb_elem = 0

    for i, j in enumerate(['left_side', 'right_side'], start=0):
        degrees = re.findall(r'X\^-?\d*\.?\d+', args[i])
        numbers = re.findall(r'-?\d*\.?\d*\*', args[i])

        for degree, number in zip(degrees, numbers):
            checker += number.replace('-', '') + degree
            nb_elem += 1
            if number != '0*' and number != '-0*':
                data[j]['degrees'].append(tools.atoif(degree.replace('X^', '')))
                data[j]['numbers'].append(tools.atoif(number.replace('*', '')))


    data['degrees'] = data['left_side']['degrees'] + data['right_side']['degrees']
    data['numbers'] = data['left_side']['numbers'] + [elem * -1 for elem in data['right_side']['numbers']]

    check(original_entry, checker, nb_elem)

    try:
        data['max_degree'] = max(data['degrees'])
    except ValueError:
        tools.print_and_quit("\n\tThere is no solution for this equation.\n")
    return data


def reduce_data(degrees, numbers):
    reduced_data = { 0: 0, 1: 0 }
    
    for i in range(len(degrees)):
        try:
            reduced_data[degrees[i]] += numbers[i]
        except KeyError:
            reduced_data[degrees[i]] = numbers[i]
    return reduced_data


def get_reduce_form(args):
    data         = extract_data([args[:args.find('=')], args[args.find('=') + 1:]], args)
    reduced_data = reduce_data(data['degrees'], data['numbers'])

    tools.print_reduced_form_and_polynomial_degree(reduced_data, data)
    tools.check_data_before_processing(data)
    return reduced_data, data['max_degree']
