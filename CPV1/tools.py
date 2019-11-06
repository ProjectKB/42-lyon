# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    tools.py                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/06 12:59:58 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/06 14:04:49 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import math
import re
import sys

def roundornot(nb, mod):
    return int(nb) if nb.is_integer() else nb if mod == 1 else\
                                    int(nb) if nb.is_integer() else round(nb, 3)

def print_reduce_form_and_polynomial_degree(r_data, max_degree):
    tmp_str = ""
    for deg, nb in r_data.items():
        nb = roundornot(nb, 1)
        deg = roundornot(deg, 1)
        tmp_str += "{nb} * X^{deg} {sign} ".format(nb=nb, deg=deg, sign='+')
    r_str = "Reduced form:\n\t" + tmp_str[:-3].replace('+ -', '- ') + " = 0\n"
    print(r_str)
    print("Polynomial degree:", max_degree, "\n")

def print_delta(delta, a, b, c):
    print("Polynomial form ( ax ^ 2 + bx + c ):")
    print("\ta:", a, "| b:", b, "| c:", c, "\n")
    print("Delta calculation ( b ^ 2 - 4ac ):")
    print("\t=", b ** 2, "- 4 *", a, "*", c, "")
    print("\t=", delta, "\n")

def print_second_degree(delta, a, b, c, resultat, x1, x2):
    if delta < 0:
        print("Delta is smaller than 0 so there is no solution to the equation.")
    elif delta == 0:
        print("Delta is equal to 0, resolution formula is : -( b / 2a )")
        print("The solution is:\n\t= -(", b, "/ ( 2 *", a, ") )")
        print("\t= ", resultat)
    elif delta > 0:
        print("Delta is greater than 0, there are two solutions to the equation.")
        print("\tx1 = ( -b - sqrt(delta) ) / 2a")
        print("\t   = (", b * -1, "-", round(math.sqrt(delta), 3), ") /", 2 * a)
        print("\t   =", x1)
        print("\tx2 = ( -b + sqrt(delta) ) / 2a")
        print("\t   = (", b * -1, "+", round(math.sqrt(delta), 3), ") /", 2 * a)
        print("\t   =", x2)
