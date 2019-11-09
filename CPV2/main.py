# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    main.py                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/08 21:20:56 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/09 20:43:46 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re

REEL = 0
IMAGINAIRE = 1
MATRICE = 2
POLY = 3

def parse_matrices(args):
        matrices = []
        args = re.findall(r'\[((\[(,?-?\d+(.\d+)?)+\];?)+)\]', args)
        for arg in args:
            lines = arg[0].split(';')
            matrix = []
            for elem in lines:
                tmp = elem.replace('[', '')
                tmp = tmp.replace(']', '')
                line = tmp.split(',')
                matrix.append(line)
            matrices.append(matrix)
        return matrices

def find_calcul_type(args):
    if re.search(r'\[((\[(,?-?\d+(.\d+)?)+\];?)+)\]', args):
        matrices = parse_matrices(args)
        print(matrices)
        print("There are some matrices in this expression.")


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
