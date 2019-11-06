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
import parsing as p
import calcul as c

def main():
    if len(sys.argv[1:]) is not 1:
        print("Unvalid parameters number.")
    else:
        r_data, m_degree = p.get_reduce_form(sys.argv[1].replace(' ', ''))
        c.solve_equation(r_data, m_degree)

if __name__ == "__main__":
    main()
