# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    computer_v1.py                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/24 18:10:47 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/06 21:31:09 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import re
import tools

def convert_to_int_or_float(nb):
    try:
        return int(nb)
    except ValueError:
        return float(nb)


def extract_data(args):
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

    for i, j in enumerate(['left_side', 'right_side'], start=0):
        degrees = re.findall(r'X\^-?\d*\.?\d+', args[i])
        numbers = re.findall(r'-?\d*\.?\d*\*', args[i])

        [data[j]['degrees'].append(convert_to_int_or_float(degree.replace('X^', ''))) for degree in degrees]
        [data[j]['numbers'].append(convert_to_int_or_float(number.replace('*', ''))) for number in numbers]

    data['degrees']    = data['left_side']['degrees'] + data['right_side']['degrees']
    data['numbers']    = data['left_side']['numbers'] + [elem * -1 for elem in data['right_side']['numbers']]
    data['max_degree'] = max(data['degrees'])
    return data


def get_reduce_data(degrees, numbers):
    reduced_data = { 0: 0, 1: 0 }
    
    for i in range(len(degrees)):
        try:
            reduced_data[degrees[i]] += numbers[i]
        except KeyError:
            reduced_data[degrees[i]] = numbers[i]
    return reduced_data


def check_data_before_processing(data):
    if data['left_side']['numbers'] == data['right_side']['numbers'] and data['left_side']['degrees'] == data['right_side']['degrees']:
        print("\n\tThis is a special case, all real numbers are true for this equation.\n")
        exit(0)
    elif data['max_degree'] == 0:
        print("\n\tThere is no solution for this equation.\n")
        exit(0)
    elif data['max_degree'] > 2 and type(data['max_degree']) == int:
        print("\n\tThe polynomial degree is stricly greater than 2, I can't solve.\n")
        exit(0)
    elif min(data['degrees']) < 0 and type(min(data['degrees'])) == int:
        print("\n\tOne of the polynomial degree is negative, I can't solve.\n")
        exit(0)
    for degree in data['degrees']:
        if type(degree) == float:
            print("\n\tOne of the polynomial degree isn't an integer, I can't solve.\n")
            exit(0)


def get_reduce_form(args):
    data         = extract_data([args[:args.find('=')], args[args.find('=') + 1:]])
    reduced_data = get_reduce_data(data['degrees'], data['numbers'])

    tools.print_reduced_form_and_polynomial_degree(reduced_data, data)
    check_data_before_processing(data)
    return reduced_data, data['max_degree']
