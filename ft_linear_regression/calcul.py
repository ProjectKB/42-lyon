import tools

def estimatedPrice(t0, t1, km):
    return t0 + t1 * km

def min_max_normalization(data):
    normalized_data          = { 'm': data['m'] }
    normalize                = lambda elem, collection: (elem - min(collection)) / (max(collection) - min(collection))
    normalized_data['km']    = [normalize(km, data['km']) for km in data['km']]
    normalized_data['price'] = [normalize(price, data['price']) for price in data['price']]

    return normalized_data

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

def gradient_descent(ori, data, learning_rate, iterations):
    t0               = 0
    t1               = 0
    cost_history     = []
    accuracy_history = []
    curve_history    = []


    for i in range(iterations):
        t0, t1 = gradients(t0, t1, data, learning_rate)
        curve_history.append(min_max_denormalization(t0, t1, ori, data))
        cost_history.append(cost_function(t0, t1, data))
        accuracy_history.append(least_squares(t0, t1, data) * 100)
    return t0, t1, cost_history, accuracy_history, curve_history

def cost_function(t0, t1, data):
    tmp = tools.sum(t0, t1, data, lambda km, price: (estimatedPrice(t0, t1, km) - price) ** 2) / data['m']
    
    return tmp

def least_squares(t0, t1, data):
    price_average = tools.average(data['price'])
    operation_num = lambda km, price: (price - estimatedPrice(t0, t1, km)) ** 2
    operation_den = lambda km, price: (price - price_average) ** 2

    return 1 - (tools.sum(t0, t1, data, operation_num) / tools.sum(t0, t1, data, operation_den))
