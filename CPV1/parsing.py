import re
import tools

def check_syntax(args, checker, elem_nb):
    check = len(checker)
    base  = len(args)
    case1 = re.findall(r'-?\d*\.?\d*\*X\^-?\d*\.?\d+=-?\d*\.?\d*\*X\^-?\d*\.?\d+', args)
    case2 = re.findall(r'-?\d*\.?\d*\*X\^-?\d*\.?\d+=0', args)

    if case1 or case2:
        check += 1 + (elem_nb - 2) if case1 else 2 + (elem_nb - 1)
    else:
        tools.print_and_quit('Invalid Syntax, use the following form : a*x^p')
    if args[0] == '-':
        check += 1
    if check != base:
        tools.print_and_quit('Invalid Syntax, use the following form : a*x^p')


def extract_data(splitted_str, reduced_str, original_str):
    nb_elem   = 0
    check_str = ''
    data      = {
                    'left_side': {
                        'degrees': [],
                        'numbers': []
                    },
                    'right_side': {
                        'degrees': [],
                        'numbers': []
                    }
                }

    for i, j in enumerate(['left_side', 'right_side'], start=0):
        degrees = re.findall(r'X\^-?\d*\.?\d+', splitted_str[i])
        numbers = re.findall(r'-?\d*\.?\d*\*', splitted_str[i])

        for degree, number in zip(degrees, numbers):
            check_str += number.replace('-', '') + degree
            nb_elem   += 1
            if number != '0*' and number != '-0*':
                data[j]['degrees'].append(tools.atoif(degree.replace('X^', '')))
                data[j]['numbers'].append(tools.atoif(number.replace('*', '')))

    data['degrees'] = data['left_side']['degrees'] + data['right_side']['degrees']
    data['numbers'] = data['left_side']['numbers'] + [elem * -1 for elem in data['right_side']['numbers']]

    check_syntax(reduced_str, check_str, nb_elem)
    print("\n\tYou've entered:", original_str)

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


def get_reduce_form(original_str):
    reduced_str  = re.sub(r'\s+', '', original_str).replace('x', 'X')
    splitted_str = reduced_str.split('=')

    if not reduced_str or len(splitted_str) != 2:
        tools.print_and_quit('Invalid Syntax, use the following form : a*x^p')

    data         = extract_data(splitted_str, reduced_str, original_str)
    reduced_data = reduce_data(data['degrees'], data['numbers'])

    tools.print_reduced_form_and_polynomial_degree(reduced_data, data)
    tools.check_data_before_processing(data)
    return reduced_data, data['max_degree']
