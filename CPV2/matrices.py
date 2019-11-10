# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    main.py                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/08 21:20:56 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/11/10 21:36:43 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import tools as t
import re

def parse_matrices(args):
        matrices = []
        args = re.findall(r'(\[(\[(-?\d+(.\d+)?)(,-?\d+(.\d+)?)?\])(;\[(-?\d+(.\d+)?)(,-?\d+(.\d+)*)?\])*\])', args)
        for arg in args:
            matrix = []
            lines = arg[0].replace('[', '').replace(']', '').split(';')
            for elem in lines:
                line = elem.split(',')
                matrix.append(line)
            length = len(matrix[0])
            if all(len(line) == length for line in matrix):
                m_size = [length, len(matrix)]
                matrix.append(m_size)
                matrices.append(matrix)
            else:
                print("Error : One of your matrice is incorrectly formatted.")
                return -1
        return matrices

def multiply_matrices(m1, op, v):
    new_matrix = []
    dim = {'m1': {'x': m1[-1][0], 'y': m1[-1][1]}, 'm2': {'x': v[-1][0], 'y': v[-1][1]}}
    if dim['m1']['x'] != dim['m2']['y']:
        print("Error : M1's columns number must be equal to M2's rows number.")
        return -1
    for l in range(dim['m1']['y']):
        tmp_line = []
        for i in range(dim['m2']['x']):
            elem = 0
            for j in range(dim['m1']['x']):
                elem += t.do_op(m1[l][j], v[j][i], "*")
            tmp_line.append(elem)
        new_matrix.append(tmp_line)
    new_matrix.append([max(m1[-1]), max(m1[-1])])
    return new_matrix

def op_on_matrices(m1, op, nb):
    new_matrix = []
    for line in m1[:-1]:
        tmp_line = []
        for elem in line:
            tmp_line.append(t.do_op(elem, nb, op))
        new_matrix.append(tmp_line)
    new_matrix.append(m1[-1])
    return new_matrix

def op_between_matrices(m1, op, m2):
    new_matrix = []
    if m1[-1] != m2[-1]:
        print("Error : You can't add/substract matrices of different sizes.")
        return -1
    for (l1, l2) in zip(m1[:-1], m2[:-1]):
        tmp_line = []
        for (e1, e2) in zip(l1, l2):
            tmp_line.append(t.do_op(e1, e2, op))
        new_matrix.append((tmp_line))
    new_matrix.append(m1[-1])
    return new_matrix

def print_matrix(matrix):
    print("")
    for line in matrix[:-1]:
        tmp_str = '[ '
        for elem in line:
            tmp_str += "{}, ".format(t.roundornot(elem))
        tmp_str += ']'
        print(tmp_str.replace(', ]', ' ]'))

def print_matrices(matrices):
    for matrix in matrices:
        print_matrix(matrix)

def do_op_matrices(m1, op, v):
    if op == '**':
        return multiply_matrices(m1, op, v)
    elif op == "^" and isinstance(v, int) and v >= 0:
        new_matrix = m1
        for i in range(1, v):
            new_matrix = multiply_matrices(new_matrix, "**", m1)
        return(new_matrix)
    if op == "/" and isinstance(v, list):
        return multiply_matrices(m1, op, op_on_matrices(v, "*", -1))
    elif isinstance(v, list) and (op == "*" or op == "-" or op == "+"):
        return op_between_matrices(m1, op, v)
    elif not isinstance(v, list) and (op != "+" or op == "-"):
        return op_on_matrices(m1, op, v)
