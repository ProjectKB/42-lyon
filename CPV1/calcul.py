# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    calcul.py                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/05 17:36:41 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/05 22:08:02 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re
import math
import parsing

def calcul_delta(reduce_data):
    ordered_data = {}
    ordered_data['a'] = int(reduce_data[2.0]) if reduce_data[2.0].is_integer() else reduce_data[2.0]
    ordered_data['b'] = 0 if 1.0 not in reduce_data else \
        int(reduce_data[1.0]) if reduce_data[1.0].is_integer() else reduce_data[1.0]
    ordered_data['c'] = 0 if 0.0 not in reduce_data else \
        int(reduce_data[0.0]) if reduce_data[0.0].is_integer() else reduce_data[0.0]
    delta = ordered_data['b'] ** 2 - 4 * ordered_data['a'] * ordered_data['c']
    if isinstance(delta, int):
        delta = int(delta)
    print("Polynomial form ( ax ^ 2 + bx + c ):")
    print("\ta:", ordered_data['a'], "| b:", ordered_data['b'], "| c:", ordered_data['c'], "\n")
    print("Delta calculation ( b ^ 2 - 4ac ):")
    print("\t=", ordered_data['b'] ** 2, "- 4 *", ordered_data['a'], "*", ordered_data['c'], "")
    print("\t=", delta, "\n")
    return ordered_data, delta

def second_degree(ordered_data, delta):
    if delta < 0:
        print("Delta is smaller than 0 so there is no solution to the equation.")
    elif delta == 0:
        print("Delta is equal to 0, resolution formula is : -( b / 2a )")
        print("The solution is:\n\t= -(", ordered_data['b'], "/ ( 2 *", ordered_data['a'], ") )")
        resultat = (ordered_data['b'] / (2 * ordered_data['a'])) * -1
        if resultat.is_integer():
            resultat = int(resultat)
        print("\t= ", resultat)
    elif delta > 0:
        print("Delta is greater than 0, there are two solutions to the equation.")
        x1 = (ordered_data['b'] * -1 - math.sqrt(delta)) / (2 * ordered_data['a'])
        x1 = int(x1) if x1.is_integer() else round(x1, 3)
        x2 = (ordered_data['b'] * -1 + math.sqrt(delta)) / (2 * ordered_data['a'])
        x2 = int(x2) if x2.is_integer() else round(x2, 3)
        print("\tx1 = ( -b - sqrt(delta) ) / 2a")
        print("\t   = (", ordered_data['b'] * -1, "-", round(math.sqrt(delta), 3), ") /", 2 * ordered_data['a'])
        print("\t   =", x1)
        print("\tx2 = ( -b + sqrt(delta) ) / 2a")
        print("\t   = (", ordered_data['b'] * -1, "+", round(math.sqrt(delta), 3), ") /", 2 * ordered_data['a'])
        print("\t   =", x2)

def define_method(reduce_data, max_degree):
    if max_degree == 0:
        pass
    elif max_degree == 1:
        pass
    else:
        ordered_data, delta = calcul_delta(reduce_data)
        second_degree(ordered_data, delta)

def main():
    if len(sys.argv[1:]) is not 1:
        print("Unvalid parameters number.")
    else:
        reduce_data, max_degree = parsing.get_reduce_form(sys.argv[1].replace(' ', ''))
        define_method(reduce_data, max_degree)

if __name__ == "__main__":
    main()
