# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    computer_v1.py                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/24 18:10:47 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/05 21:06:49 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re

def extract_data(args, part):
    degrees = re.findall(r'X\^-?\d*\.?\d+', args)
    degrees = [float(degree.replace('X^', '')) for degree in degrees]
    numbers = re.findall(r'-?\d*\.?\d*\*', args)
    numbers = [number.replace('*', '') for number in numbers] if part == 1 \
    else [float(number.replace('*', '')) * -1 for number in numbers]
    return degrees, numbers

def get_reduce_data(degrees, numbers):
    data = []
    expression = {}
    for i in range(len(degrees)):
        tmp_obj = {'deg': degrees[i], 'nb': numbers[i]}
        data.append(tmp_obj)
    for degree in degrees:
        if degree not in expression:
            expression[degree] = 0
    for arg in data:
        expression[arg['deg']] += float(arg['nb'])
    return expression

def print_reduce_form_and_polynomial_degree(reduce_data, max_degree):
    tmp_string = ""
    for deg, nb in reduce_data.items():
        if nb.is_integer():
            nb = int(nb)
        if deg.is_integer():
            deg = int(deg)
        tmp_string += "{nb} * X^{deg} {sign} ".format(nb=nb, deg=deg, sign='+')
    reduce_string = "Reduced form:\n\t" + tmp_string[:-3].replace('+ -', '- ') + " = 0\n"
    print(reduce_string)
    print("Polynomial degree:", max_degree, "\n")

def find_max_degree(degrees):
    degrees_tmp = []
    for deg in degrees:
        if deg.is_integer():
            deg = int(deg)
        degrees_tmp.append(deg)
    return max(degrees_tmp)

def check_data_before_processing(degrees):
    if max(degrees) > 2:
        print("The polynomial degree is stricly greater than 2, I can't solve.")
        sys.exit(0)
    for deg in degrees:
        if not (deg == 0 or deg == 1 or deg == 2):
            print("One of the polynomial degree is invalid (negative or float), I can't solve.")
            sys.exit(0)

def get_reduce_form(args):
    f_part = args[:args.find('=')]
    s_part = args[args.find('=') + 1:]
    f_deg, f_num = extract_data(f_part, 1)
    s_deg, s_num = extract_data(s_part, 2)
    degrees = f_deg + s_deg
    numbers = f_num + s_num
    reduce_data = get_reduce_data(degrees, numbers)
    max_degree = find_max_degree(degrees)
    print_reduce_form_and_polynomial_degree(reduce_data, max_degree)
    check_data_before_processing(degrees)
    return reduce_data, max_degree
