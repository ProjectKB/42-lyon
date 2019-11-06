# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    tools.py                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/06 12:59:58 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/06 21:06:22 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import re
import sys

def roundornot(nb):
    nb = float(nb)
    return int(nb) if nb.is_integer() else round(nb, 3)

def print_reduce_form_and_polynomial_degree(r_data, max_degree, special, args):
    if special is False:
        tmp_str = ""
        for deg, nb in r_data.items():
            nb = roundornot(nb)
            deg = roundornot(deg)
            if not (deg == 0 or deg == 1 or deg == 2):
                tmp_str += "{nb}x^{deg} {sign} ".format(nb=nb, deg=deg, sign='+')
            else:
                if deg == 0:
                    tmp_str += "{nb} {sign} ".format(nb=nb, sign='+')
                elif deg == 2:
                    tmp_str += str(nb) + "x\u00B2 + "
                else:
                    tmp_str += "{nb}x {sign} ".format(nb=nb, sign='+')
        r_str = "\n\tReduced form: " + tmp_str[:-3].replace('+ -', '- ') + " = 0"
        print(r_str)
    else:
        print("\n\tThere is no reduce form for this equation.")
    print("\tPolynomial degree:", max_degree)

def print_delta(delta, a, b, c):
    print("\tPolynomial form: ax\u00B2 + bx + c \n\n" \
        "\tDelta formula: b\u00B2 - 4ac\n" + \
        "\tCoefficients: a =",  str(a) + ", b =", str(b) + ", c = " + str(c) + \
        "\n\t=", roundornot(b ** 2), "- 4 * "+ str(a) + " * " + str(c) + \
        "\n\t=", delta, "\n")

def print_second_degree(delta, a, b, c, resultat, x1, x2):
    if delta < 0:
        print("\tDelta is smaller than 0 so there is no solution to the equation.\n")
    elif delta == 0:
        print("\tDelta is equal to 0.\n\t" + "Resolution formula: -(b / 2a)\n\n" + \
            "\tThe solution is:\n\t= -(" + str(b) + "/ (2 *", str(a) + ")\n" + \
            "\t= " + str(resultat) + "\n")
    elif delta > 0:
        print("\tDelta is greater than 0, there are two solutions to the equation.\n\n" + \
            "\tResolution formula: x\u2081, x\u2082 = (-b ± \u221A\u0394) / 2a\n\n" + \
            "\tSolutions are:\n" + \
            "\tx\u2081 = (", b * -1, "-", round(delta ** 0.5, 3), ") /", 2 * a, "\n" + \
            "\t   = " + str(x1) + "\n" + \
            "\tx\u2082 = (", b * -1, "+", round(delta ** 0.5, 3), ") /", 2 * a, "\n" + \
            "\t   = " + str(x2) + "\n")
