import re
import tools
import display

def check_syntax(args, checker, elem_nb, check_sign):
    check = len(checker) + check_sign
    base  = len(args)
    case1 = re.findall(r'-?\d*\.?\d*\*X\^-?\d*\.?\d+=-?\d*\.?\d*\*X\^-?\d*\.?\d+', args)
    case2 = re.findall(r'-?\d*\.?\d*\*X\^-?\d*\.?\d+=0', args)

    if case1 or case2:
        check += 1 + (elem_nb - 2) if case1 else 2 + (elem_nb - 1)
    else:
        display.quit('Invalid Syntax, use the following form : a*x^p')
    if args[0] == '-':
        check += 1
    if args[args.index('=') + 1] == '-':
        check += 1
    if check != base:
        display.quit('Invalid Syntax, use the following form : a*x^p')


def extract_data(splitted_str, reduced_str, original_str):
    nb_elem    = 0
    check_str  = ''
    check_sign = len(re.findall(r'--|\+-|-\+', reduced_str))
    data       = {
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
        splitted_str[i] = splitted_str[i].replace('--', '+').replace('-+', '-').replace('+-', '-')
        degrees         = re.findall(r'X\^-?\d*\.?\d+', splitted_str[i])
        numbers         = re.findall(r'-?\d*\.?\d*\*', splitted_str[i])

        for degree, number in zip(degrees, numbers):
            check_str += number.replace('-', '') + degree
            nb_elem   += 1
            
            if number != '0*' and number != '-0*':
                data[j]['degrees'].append(tools.atoif(degree.replace('X^', '')))
                data[j]['numbers'].append(tools.atoif(number.replace('*', '')))

    data['degrees'] = data['left_side']['degrees'] + data['right_side']['degrees']
    data['numbers'] = data['left_side']['numbers'] + [elem * -1 for elem in data['right_side']['numbers']]

    check_syntax(reduced_str, check_str, nb_elem, check_sign)
    print("\n\tYou've entered:", original_str)
    return data


def reduce_data(degrees, numbers):
    reduced_data = {}

    numbers = list(map(tools.roundornot, numbers))
    for i in range(len(degrees)):
        try:
            reduced_data[degrees[i]] = tools.roundornot(reduced_data[degrees[i]] + numbers[i])
        except KeyError:
            reduced_data[degrees[i]] = numbers[i]
    return tools.clean_data(reduced_data)


def get_reduce_form(original_str):
    reduced_str  = re.sub(r'\s+', '', original_str).replace('x', 'X')
    splitted_str = reduced_str.split('=')

    if not reduced_str or len(splitted_str) != 2:
        display.quit('Invalid Syntax, use the following form : a*x^p')

    data         = extract_data(splitted_str, reduced_str, original_str)
    reduced_data = reduce_data(data['degrees'], data['numbers'])

    tools.check_special_case(reduced_data, data)
    display.reduced_form_and_polynomial_degree(reduced_data, data)
    tools.check_data_before_processing(data, reduced_data)
    return reduced_data, max(reduced_data.keys())
