import tools

def quit(str):
    print(str)
    exit(0)

def reduced_form_and_polynomial_degree(reduced_data, data):
    reduced_str = ""

    for degree, number in reduced_data.items():
        number = tools.roundornot(number)
        degree = tools.roundornot(degree)

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
            "\n\tPolynomial degree:", max(reduced_data.keys()))

def delta(delta, a, b, c):
    print("\tPolynomial form: ax\u00B2 + bx + c \n\n" \
        "\tDelta formula: b\u00B2 - 4ac\n" + \
        "\tCoefficients: a =",  str(a) + ", b =", str(b) + ", c = " + str(c) + \
        "\n\t= " + str(b * b) + " - (4 * "+ str(a) + " * " + str(c) + ")" \
        "\n\t= " + str(delta) + "\n")

def second_degree(delta, a, b, c, resultat, x1, x2):
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
            "\tx\u2081 = (" + str(b * -1) + " - " + str(tools.roundornot(tools.newton_sqrt(delta))) + ") / " +  str(2 * a) + "\n" + \
            "\t   = " + str(x1) + "\n" + \
            "\tx\u2082 = (" + str(b * -1) + " + " + str(tools.roundornot(tools.newton_sqrt(delta))) + ") / " + str(2 * a) + "\n" + \
            "\t   = " + str(x2) + "\n")