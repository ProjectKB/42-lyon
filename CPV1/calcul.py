# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    calcul.py                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/05 17:36:41 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/06 21:05:35 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import tools

def calcul_delta(reduced_data):
    unknown = {
        'a': tools.roundornot(reduced_data[2]),
        'b': 0 if 1 not in reduced_data else tools.roundornot(reduced_data[1]),
        'c': 0 if 0 not in reduced_data else tools.roundornot(reduced_data[0])
    }
    delta = tools.roundornot(unknown['b'] ** 2 - 4 * unknown['a'] * unknown['c'])
    
    tools.print_delta(delta, unknown['a'], unknown['b'], unknown['c'])
    return unknown, delta

def second_degree(unknown, delta):
    if delta < 0:
        tools.print_second_degree(delta, unknown['a'], unknown['b'], unknown['c'], 0, 0, 0)
    elif delta == 0:
        resultat = tools.roundornot((unknown['b'] / (2 * unknown['a'])) * -1)
        tools.print_second_degree(delta, unknown['a'], unknown['b'], unknown['c'], resultat, 0, 0)
    elif delta > 0:
        x1 = tools.roundornot((unknown['b'] * -1 - delta ** 0.5) / (2 * unknown['a']))
        x2 = tools.roundornot((unknown['b'] * -1 + delta ** 0.5) / (2 * unknown['a']))
        tools.print_second_degree(delta, unknown['a'], unknown['b'], unknown['c'], 0, x1, x2)

def solve_equation(reduced_data, max_degree):
    if max_degree == 1:
        resultat = tools.roundornot(reduced_data[0] * -1 / reduced_data[1])
        print("\n\tThe solution is:\n\t= " + str(resultat) + "\n")
    else:
        unknown, delta = calcul_delta(reduced_data)
        second_degree(unknown, delta)
