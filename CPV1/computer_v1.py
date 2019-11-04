# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    computer_v1.py                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/24 18:10:47 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/04 16:18:23 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re

def get_arg(arg):
    expr = {}
    # -? -> - 0 ou 1 fois \\d+ un chiffre un nombre x de fois
    expr['obj'] = re.search('X\\^-?\\d+', arg)
    expr['nb'] = arg[:arg.find('*')]
    expr['str'] = expr['obj'].group(0)
    expr['deg'] = expr['str'].replace('X^', '')
    expr['new'] = arg[expr['obj'].end():]
    return expr

def main():
    if len(sys.argv[1:]) is not 1:
        print("Unvalid parameters number.")
    else :
        arg =  get_arg(sys.argv[1].replace(' ', ''))
        print(list(arg.items())[1:])
        while arg['new']:
            arg =  get_arg(arg['new'])
            print(list(arg.items())[1:])

if __name__ == "__main__":
    main()
