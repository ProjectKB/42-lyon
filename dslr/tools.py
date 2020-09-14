import display

def bubble_sort(collection):
    i = 0

    while i != count(collection) - 1:
        if collection[i] > collection[i + 1]:
            collection[i]     ^= collection[i + 1]
            collection[i + 1] ^= collection[i]
            collection[i]     ^= collection[i + 1]
            i                  = 0
        else:
            i += 1
    return collection

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

def quartile(collection, count, q):
    if q == 1:
        return collection[int(percentage(25, count))]
    elif q == 2:
        return median(collection, count)
    elif q == 3:
        return collection[int(percentage(75, count))]

def convert_to_number(str):
    try:
        try:
            return int(str)
        except ValueError:
            return float(str)
    except ValueError:
        return 0
