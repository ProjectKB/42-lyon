# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    computer_v1.py                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/24 18:10:47 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/06 20:11:13 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import re
import tools as t

def multiply_list_by(nb):
    return nb * -1

def extract_data(args):
    degrees = re.findall(r'X\^-?\d*\.?\d+', args)
    degrees = [float(degree.replace('X^', '')) for degree in degrees]
    numbers = re.findall(r'-?\d*\.?\d*\*', args)
    numbers = [float(number.replace('*', '')) for number in numbers]
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

def find_max_degree(degrees):
    degrees_tmp = []
    for deg in degrees:
        degrees_tmp.append(deg)
    return t.roundornot(max(degrees_tmp))

def check_data_before_processing(degrees, m_degree, f_num, s_num, f_deg, s_deg):
    if f_num == s_num and f_deg == s_deg:
        print("\n\tThis is a special case, all real numbers are true for this equation.\n")
        exit(0)
    elif m_degree == 0:
        print("\n\tThere is no solution to this equation.\n")
        exit(0)
    elif max(degrees) > 2:
        print("\n\tThe polynomial degree is stricly greater than 2, I can't solve.\n")
        exit(0)
    elif min(degrees) < 0:
        print("\n\tOne of the polynomial degree is negative, I can't solve.\n")
        exit(0)
    for deg in degrees:
        if not (deg == 0 or deg == 1 or deg == 2):
            print("\n\tOne of the polynomial degree isn't an integer, I can't solve.\n")
            exit(0)


def get_reduce_form(args):
    f_part = args[:args.find('=')]
    s_part = args[args.find('=') + 1:]
    f_deg, f_num = extract_data(f_part)
    s_deg, s_num = extract_data(s_part)
    degrees = f_deg + s_deg
    numbers = f_num + list(map(multiply_list_by, s_num))
    m_degree = find_max_degree(degrees)
    r_data = get_reduce_data(degrees, numbers)
    t.print_reduce_form_and_polynomial_degree(r_data, m_degree, f_num == s_num, args)
    check_data_before_processing(degrees, m_degree, f_num, s_num, f_deg, s_deg)
    return r_data, m_degree
