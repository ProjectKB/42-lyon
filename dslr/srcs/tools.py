import numpy as np
from srcs.display import print_error

def debug(e):
    print(e)
    exit()

def percentage(percent, nb):
    return nb * percent / 100

def roundornot(nb):
    return int(nb) if int(nb) == float(nb) else round(nb, 3)

def mean(collection):
    v = 0

    for elem in collection:
        v += elem
    return v / count(collection)

def special_mean(collection, count):
    v = 0

    for elem in collection:
        v += elem
    return v / count

def count(collection):
    count = 0

    for _ in collection:
        count += 1
    return count

def newton_sqrt(x):
    z = 1.0

    for _ in range(0, 10):
        z -= (z * z - x) / (2 * z)
    return z

def standard_deviation(collection):
    v = 0
    m = mean(collection)

    for elem in collection:
        v += (elem - m) ** 2
    return newton_sqrt(v / count(collection))

def min(collection, count):
    v = collection[0]

    for i in range(1, count):
        if collection[i] < v:
            v = collection[i]
    return v

def max(collection, count):
    v = collection[0]

    for i in range(1, count):
        if collection[i] > v:
            v = collection[i]
    return v

def isEven(nb):  
    return True if nb ^ 1 == nb + 1 else False 

def median(collection, count):
    if isEven(count):
        return (collection[int(count / 2) - 1] + collection[int(count / 2)]) / 2
    return collection[int(count / 2)]

def quartile(sorted_collection, count, q):
    if q == 1:
        return sorted_collection[int(percentage(25, count))]
    elif q == 2:
        return median(sorted_collection, count)
    elif q == 3:
        return sorted_collection[int(percentage(75, count))]

def convert_to_number(str):
    try:
        try:
            return int(str)
        except ValueError:
            return float(str)
    except ValueError:
        return 0

def special_convert_to_number(str, rm, feature_name):
    try:
        try:
            return int(str)
        except ValueError:
            return float(str)
    except ValueError:
        return rm[feature_name]['mean']

def get_values_for_standardization(dataset_by_features, CONST):
    return { values: { valid_feature: CONST.ROWS_FUNCTION[values](dataset_by_features[valid_feature], count(dataset_by_features[valid_feature])) for valid_feature in CONST.VALID_FEATURES } for values in ['Mean', 'Std'] }

def standardize(elem, avg, std):
    return (elem - avg) / std

def is_valid_dataset(dataset_name):
    if dataset_name != 'datasets/dataset_test.csv' and dataset_name != 'datasets/dataset_train.csv':
        print_error("Use one of the datasets present in the 'datasets' folder.")

def is_train_dataset(dataset_name):
    if dataset_name != 'datasets/dataset_train.csv':
        print_error("You have to use datasets/dataset_train.csv.")

def write_thetas(T, CONST):
    file = open('thetasValue','w')
    str  = ""

    for house_name, thetas in zip(CONST.HOUSES_NAME, T):
        str += house_name + ': '
        for theta in thetas:
            str += '|' + np.array2string(theta) + '|'
        str += '\n'

    file.write(str)
    file.close()

def real_mean(data, CONST):
    rm = { valid_feature: {} for valid_feature in CONST.VALID_FEATURES }
    
    for valid_feature in CONST.VALID_FEATURES:
        rm[valid_feature]['count'] = data[valid_feature].count(0)
        rm[valid_feature]['mean'] = special_mean(data[valid_feature], count(data[valid_feature]) - rm[valid_feature]['count'])
    return rm

def fix_data(data, rm, CONST):
    for valid_feature in CONST.VALID_FEATURES:
        for _ in range(0, rm[valid_feature]['count']):
            i = data[valid_feature].index(0)
            data[valid_feature][i] = rm[valid_feature]['mean']
    return data
