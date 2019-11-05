# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    calcul.py                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/05 17:36:41 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/05 21:11:42 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re
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
    print("\ta:", ordered_data['a'], "b:", ordered_data['b'], "c:", ordered_data['c'], "\n")
    print("Delta calculation ( b ^ 2 - 4ac ):")
    print("\t=", ordered_data['b'] ** 2, "- 4 *", ordered_data['a'], "*", ordered_data['c'], "")
    print("\t=", delta, "\n")
    return ordered_data, delta

def second_degree(ordered_data, delta):
    if delta < 0:
        print("Delta is smaller than 0 so there is no solution to the equation.")
    elif delta == 0:
        print("Delta is equal to 0, resolution formula is : -(b / 2a)")
        print("The solution is:\n\t= -(", ordered_data['b'], "/ ( 2 *", ordered_data['a'], ") )")
        resultat = (ordered_data['b'] / (2 * ordered_data['a'])) * -1
        if resultat.is_integer():
            resultat = int(resultat)
        print("\t= ", resultat)

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
