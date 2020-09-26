import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

def histogram(data_sorted_by_house, CONST):
    plt.figure(figsize=(10, 7))
    plt.suptitle('Scores Distribution Between the Different Houses')
    for j in range (1, 14):
        plt.subplot(3, 5, j + 1) 
        for house_name, color in zip(CONST.HOUSES_NAME, CONST.COLORS):
            plt.hist(data_sorted_by_house[house_name][CONST.FEATURES_NAME[j]], alpha=0.5, color=color)
        plt.tick_params(axis='both', which='both', left=False, labelleft=False, bottom=False, labelbottom=False)
        plt.xlabel(CONST.FEATURES_NAME[j])
        if j == 1:
            plt.legend(CONST.HOUSES_NAME, bbox_to_anchor=(-0.15, 0.8))
    plt.show()

def scatter(dataset):
    plt.figure(figsize=(10, 7))
    plt.title('Evolution of Defense Against the Dark Arts according to Astronomy')
    plt.scatter(dataset['Defense Against the Dark Arts'], dataset['Astronomy'])
    plt.tick_params(axis='both', labelbottom=False, labelleft=False, length=0)
    plt.xlabel('Defense Against the Dark Arts')
    plt.ylabel('Astronomy')
    plt.show()

def scatter_demo(dataset, FEATURES_NAME):
    for feature_name1 in FEATURES_NAME:
        for feature_name2 in FEATURES_NAME:
            if feature_name1 != feature_name2:
                plt.figure(figsize=(10, 7))
                plt.title('Evolution of ' + feature_name1 + ' according to ' + feature_name2)
                plt.scatter(dataset[feature_name1], dataset[feature_name2])
                plt.tick_params(axis='both', labelbottom=False, labelleft=False, length=0)
                plt.xlabel(feature_name1)
                plt.ylabel(feature_name2)
                plt.show()

def pair_plot(dataset, CONST):
    for elem in CONST.TO_REMOVE:
        dataset.pop(elem)
    sns.set_style("white")
    g = sns.pairplot(pd.DataFrame(dataset), y_vars=['Astronomy', 'Herbology', 'Ancient Runes'], hue='Hogwarts House', height=2)
    g.set(xticklabels=[], yticklabels=[])
    sns.despine(right=False, top=False)
    plt.show()

def pair_plot_demo(dataset, CONST):
    for elem in CONST.TO_REMOVE_DEMO:
        dataset.pop(elem)
    sns.set_style("white")
    g1 = sns.pairplot(pd.DataFrame(dataset), y_vars=['Astronomy', 'Herbology', 'Divination', 'Muggle Studies'], hue='Hogwarts House', height=1.5)
    g1.set(xticklabels=[], yticklabels=[])
    sns.despine(right=False, top=False)
    g2 = sns.pairplot(pd.DataFrame(dataset), y_vars=['History of Magic', 'Ancient Runes', 'Charms', 'Flying'], x_vars=['History of Magic', 'Ancient Runes', 'Charms', 'Flying', 'Astronomy', 'Herbology', 'Divination', 'Muggle Studies'], hue='Hogwarts House', height=1.5)
    g2.set(xticklabels=[], yticklabels=[])
    sns.despine(right=False, top=False)
    plt.show()
