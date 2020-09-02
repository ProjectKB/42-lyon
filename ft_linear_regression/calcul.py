import tools

def estimatedPrice(t0, t1, km):
    return t0 + t1 * km

def min_max_normalization(data):
    normalize     = lambda elem, collection: (elem - min(collection)) / (max(collection) - min(collection))
    data['km']    = [normalize(km, data['km']) for km in data['km']]
    data['price'] = [normalize(price, data['price']) for price in data['price']]

    return data

def min_max_denormalization(t0, t1, data, normalized_data):
    denormalize       = lambda elem, collection: elem * (max(collection) - min(collection)) + min(collection)
    denormalized_data = [denormalize(estimatedPrice(t0, t1, km), data['price']) for km in normalized_data['km']]

    return denormalized_data

def gradients(t0, t1, data, learning_rate):
    sum0 = tools.sum(t0, t1, data, lambda km, price: estimatedPrice(t0, t1, km) - price)
    sum1 = tools.sum(t0, t1, data, lambda km, price: (estimatedPrice(t0, t1, km) - price) * km)
    t0  -= learning_rate * (sum0 / data['m'])
    t1  -= learning_rate * (sum1 / data['m'])
    
    return t0, t1

def gradient_descent(data, learning_rate, iterations):
    t0 = 0
    t1 = 0

    for i in range(iterations):
        t0, t1 = gradients(t0, t1, data, learning_rate)
    return t0, t1

def cost_function(t0, t1, data):
    return tools.sum(t0, t1, data, lambda km, price: (estimatedPrice(t0, t1, km) - price) ** 2) / data['m']

def least_squares(t0, t1, data):
    price_average = tools.average(data['price'])
    operation_num = lambda km, price: (price - estimatedPrice(t0, t1, km)) ** 2
    operation_den = lambda km, price: (price - price_average) ** 2

    return 1 - (tools.sum(t0, t1, data, operation_num) / tools.sum(t0, t1, data, operation_den))
