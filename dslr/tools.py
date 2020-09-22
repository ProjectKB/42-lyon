import display

def percentage(percent, nb):
    return nb * percent / 100

def roundornot(nb):
    return int(nb) if int(nb) == float(nb) else round(nb, 3)

def mean(collection):
    v = 0

    for elem in collection:
        v += elem
    return v / count(collection)

def count(collection):
    count = 0

    for elem in collection:
        count += 1
    return count

def newton_sqrt(x):
    z = 1.0

    for i in range(0, 10):
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

def standardize(elem, avg, std):
    return (elem - avg) / std

def dataset_standardization(dataset, FEATURES_NAME):
    dataset_standardized = { feature_name: [] for feature_name in FEATURES_NAME }

    for feature_name in FEATURES_NAME:
        avg = mean(dataset[feature_name])
        std = standard_deviation(dataset[feature_name])

        for elem in dataset[feature_name]:
            dataset_standardized[feature_name].append(standardize(elem, avg, std))
    return dataset_standardized


def histo_standardization(dataset, FEATURES_NAME, HOUSES_NAME):
    dataset_standardized = { house_name: { feature_name: [] for feature_name in FEATURES_NAME } for house_name in HOUSES_NAME }

    for house_name in HOUSES_NAME:
        for feature_name in FEATURES_NAME:
            avg = mean(dataset[house_name][feature_name])
            std = standard_deviation(dataset[house_name][feature_name])

            for elem in dataset[house_name][feature_name]:
                dataset_standardized[house_name][feature_name].append(standardize(elem, avg, std))
    return dataset_standardized

def check_dataset_name(dataset_name):
    if dataset_name != 'datasets/dataset_test.csv' and dataset_name != 'datasets/dataset_train.csv':
        display.print_error("Use one of the datasets present in the 'datasets' folder.")
