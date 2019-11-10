# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    tools.py                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/10 20:01:11 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/10 21:47:03 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

def roundornot(nb):
    nb = float(nb)
    return int(nb) if nb.is_integer() else round(nb, 3)

def do_op(v1, v2, op):
    if op == "+":
        return round(float(v1) + float(v2), 3)
    elif op == "-":
        return round(float(v1) - float(v2), 3)
    elif op == "*":
        return round(float(v1) * float(v2), 3)
    elif op == "/":
        return round(float(v1) / float(v2), 3)
    elif op == "%":
        return round(float(v1) % float(v2), 3)
    elif op == "^":
        return round(float(v1) ** v2, 3)
