import tools

def estimatedPrice(t0, t1, km):
    return t0 + t1 * km

def sum(t0, t1, data, operation):
    v = 0

    for km, price in zip(data['km'], data['price']):
        v += operation(km, price)
    return v

def cost_function(t0, t1, data):
    return sum(t0, t1, data, lambda km, price: (estimatedPrice(t0, t1, km) - price) ** 2) / data['m']

def get_gradient(t0, t1, data, learning_rate):
    sum0 = sum(t0, t1, data, lambda km, price: estimatedPrice(t0, t1, km) - price)
    sum1 = sum(t0, t1, data, lambda km, price: (estimatedPrice(t0, t1, km) - price) * km)

    t0  -= learning_rate * (sum0 / data['m'])
    t1  -= learning_rate * (sum1 / data['m'])

    print(t0, t1)
    return t0, t1

def gradient_descent(data, learning_rate, iterations):
    t0 = 0
    t1 = 0

    for i in range(iterations):
        t0, t1 = get_gradient(t0, t1, data, learning_rate)
    return t0, t1

def least_squares(t0, t1, data):
    price_average = tools.average(data['price'])
    operation_num = lambda km, price: (price - estimatedPrice(t0, t1, km)) ** 2
    operation_den = lambda km, price: (price - price_average) ** 2

    return 1 - (sum(t0, t1, data, operation_num) / sum(t0, t1, data, operation_den))
