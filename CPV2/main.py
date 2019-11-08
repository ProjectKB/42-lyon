# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    main.py                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/08 21:20:56 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/08 22:44:45 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import sys
import re

def assignation():
    print("This is an assignation.")

def calcul():
    print("This is a basic calcul")

def main():
    print("")
    while 42:
        try:
            args = input("-> ").replace(' ', '')
        except (EOFError, KeyboardInterrupt):
            sys.exit("\nYou're such a rude...\n")
        if args == "quit":
            sys.exit("Bye Honey !\n")
        c_assign = re.search(r'^(var\w+=|fun\w+\(x\)=)', args)
        if c_assign != None:
            c_assign = c_assign.group(0).replace('=', '')
            assignation()
        else:
            calcul()
        print(c_assign, args + "\n")


if __name__ == "__main__":
    main()
