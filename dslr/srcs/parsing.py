import csv
from srcs.display import print_error 
from srcs.tools import convert_to_number, special_convert_to_number, standardize, debug

def get_dataset(file_name, FEATURES_NAME, mod):
    try:
        with open(file_name, newline='') as csvfile:
            file    = csv.DictReader(csvfile)
            dataset = { feature_name: [] for feature_name in FEATURES_NAME }

            if not file.fieldnames:
                print_error("Please do not delete data from the dataset.")
            elif mod == 1 and file.fieldnames[6:] != FEATURES_NAME:
                print_error("Rows names of '" + file_name + "' are not valid.")
            elif mod == 2 and [file.fieldnames[1]] + file.fieldnames[6:] != FEATURES_NAME:
                print_error("Rows names of '" + file_name + "' are not valid.")
            for elem in file:
                for feature_name in FEATURES_NAME:
                    if feature_name == 'Hogwarts House' and (elem[feature_name] == 'Ravenclaw' or elem[feature_name] == 'Slytherin' or elem[feature_name] == 'Gryffindor' or elem[feature_name] == 'Hufflepuff'):
                        dataset[feature_name].append(elem[feature_name])
                    else:
                        dataset[feature_name].append(convert_to_number(elem[feature_name]))
        return dataset
    except FileNotFoundError as e:
        print_error(str(e))

def get_dataset_sorted_by_house(file_name, FEATURES_NAME, HOUSES_NAME):
    try:
        with open(file_name, newline='') as csvfile:
            file    = csv.DictReader(csvfile)
            dataset = { house_name: { feature_name: [] for feature_name in FEATURES_NAME[1:] } for house_name in HOUSES_NAME }

            if not file.fieldnames:
                print_error("Please do not delete data from the dataset.")
            elif [file.fieldnames[1]] + file.fieldnames[6:] != FEATURES_NAME:
                print_error("Rows names of '" + file_name + "' are not valid.")
            for elem in file:
                for feature_name in FEATURES_NAME[1:]:
                    dataset[elem[FEATURES_NAME[0]]][feature_name].append(convert_to_number(elem[feature_name]))
        return dataset
    except FileNotFoundError as e:
        print_error(str(e))

def get_dataset_by_house_student_and_valid_features(file_name, values_for_standardization, CONST, mod, rm):
    try:
        with open(file_name, newline='') as csvfile:
            file    = csv.DictReader(csvfile)
            dataset = { house_name: [] for house_name in CONST.HOUSES_NAME } if mod == 1 else []

            if not file.fieldnames:
                print_error("Please do not delete data from the dataset.")
            elif [file.fieldnames[1]] + file.fieldnames[6:] != CONST.FEATURES_NAME:
                print_error("Rows names of '" + file_name + "' are not valid.")
            for elem in file:
                new_elem = []
                for valid_feature in CONST.VALID_FEATURES:
                    new_elem.append(standardize(special_convert_to_number(elem[valid_feature], rm, valid_feature), values_for_standardization['Mean'][valid_feature], values_for_standardization['Std'][valid_feature])) 
                dataset[elem['Hogwarts House']].append(new_elem) if mod == 1 else dataset.append(new_elem)
        return dataset
    except FileNotFoundError as e:
        print_error(str(e))
