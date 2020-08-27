# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    main.py                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/06 14:08:39 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/06 14:19:02 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import parsing
import calcul

def main():
    if len(sys.argv[1:]) != 1:
        print("Unvalid parameters number.")
    else:
        reduced_data, max_degree = parsing.get_reduce_form(sys.argv[1].replace(' ', '').replace('x', 'X'))
        calcul.solve_equation(reduced_data, max_degree)

main()
