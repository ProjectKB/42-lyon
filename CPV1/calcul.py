import tools
import display

def calcul_delta(reduced_data):
    unknown = {
        'a': tools.roundornot(reduced_data[2]),
        'b': 0 if 1 not in reduced_data else tools.roundornot(reduced_data[1]),
        'c': 0 if 0 not in reduced_data else tools.roundornot(reduced_data[0])
    }
    delta = tools.roundornot(unknown['b'] * unknown['b'] - 4 * unknown['a'] * unknown['c'])
    
    display.delta(delta, unknown['a'], unknown['b'], unknown['c'])
    return unknown, delta

def second_degree(unknown, delta):
    if delta < 0:
        display.second_degree(delta, unknown['a'], unknown['b'], unknown['c'], 0, 0, 0)
    elif delta == 0:
        resultat = tools.roundornot((unknown['b'] / (2 * unknown['a'])) * -1)
        display.second_degree(delta, unknown['a'], unknown['b'], unknown['c'], resultat, 0, 0)
    elif delta > 0:
        x1 = tools.roundornot((unknown['b'] * -1 - tools.newton_sqrt(delta)) / (2 * unknown['a']))
        x2 = tools.roundornot((unknown['b'] * -1 + tools.newton_sqrt(delta)) / (2 * unknown['a']))
        display.second_degree(delta, unknown['a'], unknown['b'], unknown['c'], 0, x1, x2)

def solve_equation(reduced_data, max_degree):
    if max_degree == 1:
        try:
            resultat = tools.roundornot(reduced_data[0] * -1 / reduced_data[1])
        except KeyError:
            resultat = 0
        print("\n\tThe solution is:\n\t= " + str(resultat) + "\n")
    else:
        unknown, delta = calcul_delta(reduced_data)
        second_degree(unknown, delta)
