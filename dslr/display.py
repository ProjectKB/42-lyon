def print_error(str):
    print('\033[91merror:\033[0m ' + str)
    exit()

def print_bold(str, field):
    print('\033[1m%*s\033[0m'% (field, str), end='')

def print_described_dataset(described_dataset, FEATURES_NAME, ROWS_NAME):
    for i in range(4):
        print()
        for j in range(4):
            print_bold(FEATURES_NAME[i * 4 + j].upper(), 45)
            if i * 4 + j == i * 4 + 3 or i * 4 + j == 12:
                break
        print('\n')
        for row_name in ROWS_NAME:
            print_bold(row_name.upper(), -5)
            for j in range(4):
                feature_name = FEATURES_NAME[i * 4 + j]
                if not j:
                    print('%40f'% described_dataset[row_name][feature_name], end='')
                else:
                    print('%45f'% described_dataset[row_name][feature_name], end='')
                if i * 4 + j == i * 4 + 3  or i * 4 + j == 12:
                    break
            print('')
        print('')


            
                
        


