import tools

def estimatedPrice(t0, t1, km):
    return t0 + t1 * km

def collection_sum(t0, t1, data, operation):
    v = 0

    for km, price in data.items():
        v += operation(km, price)
    return v

def cost_function(t0, t1, data):
    operation = lambda km, price: (estimatedPrice(t0, t1, km) - price) ** 2

    return collection_sum(t0, t1, data, operation) / data['m']

def get_t0_and_t1(tmpt0, tmpt1, data, learning_rate):
    operation_t0 = lambda km, price: estimatedPrice(tmpt0, tmpt1, km) - price
    operation_t1 = lambda km, price: (estimatedPrice(tmpt0, tmpt1, km) - price) * estimatedPrice(t0, t1, km)
    t0           = learning_rate * (1 / data['m']) * collection_sum(tmpt0, tmpt1, data, operation_t0)
    t1           = learning_rate * (1 / data['m']) * collection_sum(tmpt0, tmpt1, data, operation_t1)

    return t0, t1

def gradient_descent(t0, t1, data, learning_rate, iterations):
    for i in range(iterations):
        t0, t1 = get_t0_and_t1(t0, t1, data, learning_rate)
    return t0, t1

def least_squares(t0, t1, data):
    price_average = tools.average(data['price'])
    operation_num = lambda km, price: (price - estimatedPrice(t0, t1, km)) ** 2
    operation_den = lambda km, price: (price - price_average) ** 2

    return 1 - (collection_sum(t0, t1, data, operation_num) / collection_sum(t0, t1, data, operation_den))
