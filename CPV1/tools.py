import display

def roundornot(nb):
    return int(nb) if int(nb) == float(nb) else round(nb, 3)

def atoif(nb):
    try:
        return int(nb)
    except ValueError:
        return float(nb)

def newton_sqrt(x):
    z = 1.0

    for i in range(0, 10):
        z -= (z*z - x) / (2*z)
    return z

def clean_data(reduced_data):
    cleaned_data = dict(reduced_data)

    for degree, number in reduced_data.items():
        if number == 0:
            del cleaned_data[degree]
    return cleaned_data

def check_data_before_processing(data, reduced_data):
    max_degree = max(reduced_data.keys())
    min_degree = min(reduced_data.keys())

    if max_degree == 0 and min_degree == 0:
        display.quit("\n\tThere is no solution for this equation.\n")
    elif max_degree > 2 and type(max_degree) == int:
        display.quit("\n\tThe polynomial degree is stricly greater than 2, I can't solve.\n")
    elif min_degree < 0 and type(min_degree) == int:
        display.quit("\n\tOne of the polynomial degree is negative, I can't solve.\n")
    for degree in reduced_data.keys():
        if type(degree) == float:
            display.quit("\n\tOne of the polynomial degree isn't an integer, I can't solve.\n")

def check_special_case(reduced_data, data):
    if not reduced_data or data['left_side']['degrees'] == data['right_side']['degrees'] and data['left_side']['numbers'] == data['right_side']['numbers']:
        display.quit("\n\tReduced form: 0 = 0\n\n\tThis is a special case, all real numbers are true for this equation.\n")

