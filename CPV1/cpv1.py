# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    computer_v1.py                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/24 18:10:47 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/05 15:19:47 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re

def extract_data(args, part):
    degrees = re.findall(r'X\^-?\d*\.?\d+', args)
    degrees = [degree.replace('X^', '') for degree in degrees]
    numbers = re.findall(r'-?\d\.?\d*\*', args)
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

def print_reduce_form(reduce_data):
    tmp_string = ""
    for deg, nb in reduce_data.items():
        if nb.is_integer():
            nb = int(nb)
        tmp_string += "{nb} * X^{deg} {sign} ".format(nb=nb, deg=deg, sign='+')
    reduce_string = "Reduced form: " + tmp_string[:-3].replace('+ -', '- ') + " = 0"
    print(reduce_string)

def get_reduce_form(args):
    f_part = args[:args.find('=')]
    s_part = args[args.find('=') + 1:]
    f_deg, f_num = extract_data(f_part, 1)
    s_deg, s_num = extract_data(s_part, 2)
    degrees = f_deg + s_deg
    numbers = f_num + s_num
    return get_reduce_data(degrees, numbers)

def main():
    if len(sys.argv[1:]) is not 1:
        print("Unvalid parameters number.")
    else:
        reduce_data = get_reduce_form(sys.argv[1].replace(' ', ''))
        print_reduce_form(reduce_data)
        
if __name__ == "__main__":
    main()
