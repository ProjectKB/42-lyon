import numpy as np

def describe_dataset(dataset, FEATURES_NAME, ROWS_FUNCTION):
    described_dataset = { row_name: { feature_name: None for feature_name in FEATURES_NAME } for row_name in ROWS_FUNCTION.keys() }

    for row_name in ROWS_FUNCTION.keys():
        for feature_name in FEATURES_NAME:
            if row_name == 'Count':
                described_dataset[row_name][feature_name] = ROWS_FUNCTION[row_name](dataset[feature_name])
            elif row_name == '25%' or row_name == '50%' or row_name == '75%':
                described_dataset[row_name][feature_name] = ROWS_FUNCTION[row_name](sorted(dataset[feature_name]), described_dataset['Count'][feature_name])
            else:
                described_dataset[row_name][feature_name] = ROWS_FUNCTION[row_name](dataset[feature_name], described_dataset['Count'][feature_name])
    return described_dataset

def pre_activate(T, X):
    return np.dot(X, T)

def activate(z):
    return 1 / (1 + np.exp(-z))

def loss(X, Y, activated):
    return (np.dot(Y, np.log(activated)) + np.dot(1 - Y, np.log(1 - activated))) / X.shape[0]

def gradient(X, Y, T, activated, learning_rate):
    return T - learning_rate * (np.dot(activated - Y, X) / X.shape[0])

def gradient_descent(X, Y, learning_rate, iterations):
    T = np.zeros(X.shape[1])

    for _ in range(iterations):
        activated = activate(pre_activate(T, X))
        T         = gradient(X, Y, T, activated, learning_rate)
    return T

            
