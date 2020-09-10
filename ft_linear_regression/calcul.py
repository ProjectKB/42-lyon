import tools

def estimatedPrice(t0, t1, km):
    return t0 + t1 * km

def normalize(elem, collection):
    return (elem - min(collection)) / (max(collection) - min(collection))

def min_max_normalization(data):
    normalized_data          = { 'm': data['m'] }
    normalized_data['km']    = [normalize(km, data['km']) for km in data['km']]
    normalized_data['price'] = [normalize(price, data['price']) for price in data['price']]

    return normalized_data

def denormalize(elem, collection):
    return elem * (max(collection) - min(collection)) + min(collection)

def min_max_denormalization(t0, t1, data, normalized_data):
    return [denormalize(estimatedPrice(t0, t1, km), data['price']) for km in normalized_data['km']]

def gradients(t0, t1, data, learning_rate):
    sum0 = tools.sum(t0, t1, data, lambda km, price: estimatedPrice(t0, t1, km) - price)
    sum1 = tools.sum(t0, t1, data, lambda km, price: (estimatedPrice(t0, t1, km) - price) * km)
    t0  -= learning_rate * (sum0 / data['m'])
    t1  -= learning_rate * (sum1 / data['m'])
    
    return t0, t1

def gradient_descent(data, reduced_data, learning_rate, iterations):
    t0               = 0
    t1               = 0
    cost_history     = []
    accuracy_history = []
    curve_history    = []

    for i in range(iterations):
        t0, t1 = gradients(t0, t1, reduced_data, learning_rate)
        curve_history.append(min_max_denormalization(t0, t1, data, reduced_data))
        cost_history.append(cost_function(t0, t1, reduced_data))
        accuracy_history.append(least_squares(t0, t1, reduced_data) * 100)
    return t0, t1, cost_history, accuracy_history, curve_history

def cost_function(t0, t1, data):
    tmp = tools.sum(t0, t1, data, lambda km, price: (estimatedPrice(t0, t1, km) - price) ** 2) / data['m']
    
    return tmp

def least_squares(t0, t1, data):
    price_average = tools.average(data['price'])
    operation_num = lambda km, price: (price - estimatedPrice(t0, t1, km)) ** 2
    operation_den = lambda km, price: (price - price_average) ** 2

    return 1 - (tools.sum(t0, t1, data, operation_num) / tools.sum(t0, t1, data, operation_den))
