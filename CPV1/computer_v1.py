# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    computer_v1.py                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/24 18:10:47 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/05 15:04:33 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re

def get_arg(arg):
    expr = {}
    # -? -> - 0 ou 1 fois \\d+ un chiffre un nombre x de fois
    expr['obj'] = re.search('X\\^-?\\d+(\.[0-9][0-9]?)?', arg)
    if arg.find('*') is -1:
        return -1
    expr['nb'] = arg[:arg.find('*')]
    if expr['nb'].find('=') is not -1:
        expr['nb'] = float(expr['nb'].replace('=', '')) * -1
    expr['deg'] = expr['obj'].group(0).replace('X^', '')
    print(expr['deg'])
    expr['new'] = arg[expr['obj'].end():]
    return expr

def format_degrees(args):
    degs_order = {}
    for arg in args:
        if arg['deg'] not in degs_order:
            degs_order[arg['deg']] = 0
    return degs_order

def get_reduce_data(args, degs_order):
    for arg in args:
        degs_order[arg['deg']] += float(arg['nb'])
    #for nb in degs_order:
        #degs_order[nb] = re.sub(r".0^", "" % degs_order[nb])
    return degs_order

def print_reduce_form(reduce_data):
    tmp_string = ""
    for deg, nb in reduce_data.items():
        tmp_string += "{nb} * X^{deg} {sign} ".format(nb=nb, deg=deg, sign='+')
    reduce_string = tmp_string[:-3].replace('+ -', '- ')
    print(reduce_string)

def main():
    if len(sys.argv[1:]) is not 1:
        print("Unvalid parameters number.")
    else:
        arg = get_arg(sys.argv[1].replace(' ', ''))
        args = [arg]
        while arg is not -1 and arg['new']:
            arg = get_arg(arg['new'])
            if arg is not -1:
                args.append(arg)
        degs_order = format_degrees(args)
        print(args)
        print(degs_order)
        reduce_data = get_reduce_data(args, degs_order)
        #print_reduce_form(reduce_data)

if __name__ == "__main__":
    main()
