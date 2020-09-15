import tools

def described_dataset(dataset, FEATURES_NAME, ROWS_FUNCTION):
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
