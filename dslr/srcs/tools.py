import numpy as np
from srcs.display import print_error

def debug(e):
    print(e)
    exit()

def percentage(percent, nb):
    return nb * percent / 100

def roundornot(nb):
    return int(nb) if int(nb) == float(nb) else round(nb, 3)

def mean(collection, count):
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
    m = mean(collection, count(collection))

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

def convert_to_number(str, fix_data=0, feature_name=None):
    try:
        try:
            return int(str)
        except ValueError:
            return float(str)
    except ValueError:
        return 0 if not fix_data else fix_data[feature_name]['mean']

def standardize(elem, avg, std):
    return (elem - avg) / std

def is_valid_dataset(dataset_name):
    if dataset_name != 'datasets/dataset_test.csv' and dataset_name != 'datasets/dataset_train.csv':
        print_error("Use one of the datasets present in the 'datasets' folder.")

def is_train_dataset(dataset_name):
    if dataset_name != 'datasets/dataset_train.csv':
        print_error("You have to use datasets/dataset_train.csv.")

def is_test_dataset(dataset_name):
    if dataset_name != 'datasets/dataset_test.csv':
        print_error("You have to use datasets/dataset_test.csv.")

def get_mean_count_std(data, CONST):
    mean_count_std = { valid_feature: {} for valid_feature in CONST.VALID_FEATURES }
    
    for valid_feature in CONST.VALID_FEATURES:
        mean_count_std[valid_feature]['count'] = data[valid_feature].count(0)
        mean_count_std[valid_feature]['mean'] = mean(data[valid_feature], count(data[valid_feature]) - mean_count_std[valid_feature]['count'])
        mean_count_std[valid_feature]['std'] = standard_deviation(data[valid_feature])
    return mean_count_std

def isEven(nb):  
    return True if nb ^ 1 == nb + 1 else False 