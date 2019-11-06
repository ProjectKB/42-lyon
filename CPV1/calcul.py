# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    calcul.py                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/05 17:36:41 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/06 14:13:17 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import math
import tools as t

def calcul_delta(r_data):
    o_d = {}
    o_d['a'] = t.roundornot(r_data[2.0], 1)
    o_d['b'] = 0 if 1.0 not in r_data else t.roundornot(r_data[1.0], 1)
    o_d['c'] = 0 if 0.0 not in r_data else t.roundornot(r_data[0.0], 1)
    delta = t.roundornot(o_d['b'] ** 2 - 4 * o_d['a'] * o_d['c'], 1)
    t.print_delta(delta, o_d['a'], o_d['b'], o_d['c'])
    return o_d, delta

def second_degree(o_d, delta):
    if delta < 0:
        t.print_second_degree()
    elif delta == 0:
        resultat = t.roundornot((o_d['b'] / (2 * o_d['a'])) * -1, 1)
        t.print_second_degree(delta, o_d['a'], o_d['b'], o_d['c'], resultat)
    elif delta > 0:
        x1 = t.roundornot((o_d['b'] * -1 - math.sqrt(delta)) / (2 * o_d['a']), 2)
        x2 = t.roundornot((o_d['b'] * -1 + math.sqrt(delta)) / (2 * o_d['a']), 2)
        t.print_second_degree(delta, o_d['a'], o_d['b'], o_d['c'], 0, x1, x2)

def solve_equation(r_data, m_degree):
    if m_degree == 0:
        print("The solution is:\n\t", t.roundornot(r_data[0.0], 1))
    elif m_degree == 1:
        resultat = t.roundornot(r_data[0.0] * -1 / r_data[1.0], 1)
        print("The solution is:\n\t", resultat)
    else:
        o_d, delta = calcul_delta(r_data)
        second_degree(o_d, delta)
