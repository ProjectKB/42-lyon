import display
import csv
import tools

def get_dataset(file_name, FEATURES_NAME):
    try:
        with open(file_name, newline='') as csvfile:
            file    = csv.DictReader(csvfile)
            dataset = { subject_name: [] for subject_name in FEATURES_NAME }

            if not file.fieldnames:
                display.print_error("Please do not delete data from the dataset.")
            elif file.fieldnames[6:] != FEATURES_NAME:
                display.print_error("Rows names of '" + file_name + "' are not valid.")
            for elem in file:
                for subject_name in FEATURES_NAME:
                    dataset[subject_name].append(tools.convert_to_number(elem[subject_name]))
        return dataset
    except FileNotFoundError as e:
        display.print_error(str(e))
