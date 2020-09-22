import display
import csv
import tools

def get_dataset(file_name, FEATURES_NAME):
    try:
        with open(file_name, newline='') as csvfile:
            file    = csv.DictReader(csvfile)
            dataset = { feature_name: [] for feature_name in FEATURES_NAME }

            if not file.fieldnames:
                display.print_error("Please do not delete data from the dataset.")
            elif file.fieldnames[6:] != FEATURES_NAME:
                display.print_error("Rows names of '" + file_name + "' are not valid.")
            for elem in file:
                for feature_name in FEATURES_NAME:
                    dataset[feature_name].append(tools.convert_to_number(elem[feature_name]))
        return dataset
    except FileNotFoundError as e:
        display.print_error(str(e))

def get_dataset_sorted_by_house(file_name, FEATURES_NAME, HOUSES_NAME):
    try:
        with open(file_name, newline='') as csvfile:
            file    = csv.DictReader(csvfile)
            dataset = { house_name: { feature_name: [] for feature_name in FEATURES_NAME[1:] } for house_name in HOUSES_NAME }

            if not file.fieldnames:
                display.print_error("Please do not delete data from the dataset.")
            elif [file.fieldnames[1]] + file.fieldnames[6:] != FEATURES_NAME:
                display.print_error("Rows names of '" + file_name + "' are not valid.")
            for elem in file:
                for feature_name in FEATURES_NAME[1:]:
                    dataset[elem[FEATURES_NAME[0]]][feature_name].append(tools.convert_to_number(elem[feature_name]))
        return dataset
    except FileNotFoundError as e:
        display.print_error(str(e))
