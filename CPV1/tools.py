def roundornot(nb):
    return int(nb) if int(nb) == float(nb) else round(nb, 3)

def atoif(nb):
    try:
        return int(nb)
    except ValueError:
        return float(nb)

def print_and_quit(str):
    print(str)
    exit(0)

def check_data_before_processing(data):
    if data['left_side']['numbers'] == data['right_side']['numbers'] and data['left_side']['degrees'] == data['right_side']['degrees']:
        print_and_quit("\n\tThis is a special case, all real numbers are true for this equation.\n")
    elif data['max_degree'] == 0:
        print_and_quit("\n\tThere is no solution for this equation.\n")
    elif data['max_degree'] > 2 and type(data['max_degree']) == int:
        print_and_quit("\n\tThe polynomial degree is stricly greater than 2, I can't solve.\n")
    elif min(data['degrees']) < 0 and type(min(data['degrees'])) == int:
        print_and_quit("\n\tOne of the polynomial degree is negative, I can't solve.\n")
    for degree in data['degrees']:
        if type(degree) == float:
            print_and_quit("\n\tOne of the polynomial degree isn't an integer, I can't solve.\n")

def print_reduced_form_and_polynomial_degree(reduced_data, data):
    if data['left_side']['degrees'] == data['right_side']['degrees'] and data['left_side']['numbers'] == data['right_side']['numbers']:
        print("\n\tReduced form: 0 = 0")
    else:
        reduced_str = ""

        for degree, number in reduced_data.items():
            number = roundornot(number)
            degree = roundornot(degree)

            if not (degree == 0 or degree == 1 or degree == 2):
                reduced_str += "{number}x^{degree} {sign} ".format(number=number, degree=degree, sign='+')
            else:
                if degree == 2 and number != 0:
                    reduced_str += str(number) + "x\u00B2 + "
                elif degree == 0 and number != 0:
                    reduced_str += "{number} {sign} ".format(number=number, sign='+')
                elif number != 0:
                    reduced_str += "{number}x {sign} ".format(number=number, sign='+')
        print("\n\tReduced form: " + reduced_str[:-3].replace('+ -', '- ') + " = 0" +
              "\n\tPolynomial degree:", data['max_degree'])

def print_delta(delta, a, b, c):
    print("\tPolynomial form: ax\u00B2 + bx + c \n\n" \
        "\tDelta formula: b\u00B2 - 4ac\n" + \
        "\tCoefficients: a =",  str(a) + ", b =", str(b) + ", c = " + str(c) + \
        "\n\t= " + str(b ** 2) + " - (4 * "+ str(a) + " * " + str(c) + ")" \
        "\n\t= " + str(delta) + "\n")

def print_second_degree(delta, a, b, c, resultat, x1, x2):
    if delta < 0:
        print("\tDelta is smaller than 0, there are two solutions to the equation.\n" + \
            "\tResolution formula: x\u2081, x\u2082 = (-b ± i\u221A|\u0394|) / 2a\n\n" + \
            "\tSolutions are:\n" + \
            "\tx\u2081 = (" + str(b * -1) + " - i\u221A" + str(-delta) + ") / " +  str(2 * a) + "\n" + \
            "\tx\u2082 = (" + str(b * -1) + " + i\u221A" + str(-delta) + ") / " + str(2 * a) + "\n")
    elif delta == 0:
        print("\tDelta is equal to 0, there is one solution to the equation.\n\t" + \
            "Resolution formula: -(b / 2a)\n\n" + \
            "\tThe solution is:\n\t= -(" + str(b) + " / (2 *", str(a) + "))\n" + \
            "\t= " + str(resultat) + "\n")
    elif delta > 0:
        print("\tDelta is greater than 0, there are two solutions to the equation.\n" + \
            "\tResolution formula: x\u2081, x\u2082 = (-b ± \u221A\u0394) / 2a\n\n" + \
            "\tSolutions are:\n" + \
            "\tx\u2081 = (" + str(b * -1) + " - " + str(roundornot(delta ** 0.5)) + ") / " +  str(2 * a) + "\n" + \
            "\t   = " + str(x1) + "\n" + \
            "\tx\u2082 = (" + str(b * -1) + " + " + str(roundornot(delta ** 0.5)) + ") / " + str(2 * a) + "\n" + \
            "\t   = " + str(x2) + "\n")
