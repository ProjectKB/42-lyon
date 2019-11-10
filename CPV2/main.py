# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    main.py                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/08 21:20:56 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/10 21:45:12 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re
import tools as t
import matrices as m

def find_calcul_type(args):
    if re.search(r'(\[(\[(-?\d+(.\d+)?)(,-?\d+(.\d+)?)?\])(;\[(-?\d+(.\d+)?)(,-?\d+(.\d+)*)?\])*\])', args):
        matrices = m.parse_matrices(args)
        if matrices != -1:
            m.print_matrices(matrices)

def processing_loop():
    while 42:
        try:
            arg = input("\n-> ").replace(' ', '')
        except (EOFError, KeyboardInterrupt):
            sys.exit("\nA true gentleman would have written \"quit\", you're such a rude...\n")
        if arg == "quit":
            sys.exit("Bye Honey !\n")
        find_calcul_type(arg)

def main():
    processing_loop()

if __name__ == "__main__":
    main()
