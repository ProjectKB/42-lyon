from srcs.tools import count, median, standard_deviation, min, max, quartile

class Const:
    ROWS_FUNCTION = {
        'Count': lambda collection: count(collection),
        'Mean':  lambda collection, count: median(collection, count),
        'Std':   lambda collection, count: standard_deviation(collection),
        'Min':   lambda collection, count: min(collection, count),
        '25%':   lambda collection, count: quartile(collection, count, 1),
        '50%':   lambda collection, count: quartile(collection, count, 2),
        '75%':   lambda collection, count: quartile(collection, count, 3),
        'Max':   lambda collection, count: max(collection, count)
    }

    FEATURES_NAME = [
        'Hogwarts House',
        'Arithmancy',
        'Astronomy',
        'Herbology',
        'Defense Against the Dark Arts',
        'Divination',
        'Muggle Studies',
        'Ancient Runes',
        'History of Magic',
        'Transfiguration',
        'Potions',
        'Care of Magical Creatures',
        'Charms',
        'Flying'
    ]

    HOUSES_NAME = [
        'Gryffindor',                
        'Slytherin',
        'Hufflepuff',                
        'Ravenclaw'                
    ]

    COLORS = [
        'red',
        'green',
        'yellow',
        'blue'
    ]

    TO_REMOVE_DEMO = [
        'Arithmancy',
        'Care of Magical Creatures',
        'Potions',
        'Defense Against the Dark Arts',
        'Transfiguration'
    ]

    TO_REMOVE = [
        'Arithmancy',
        'Defense Against the Dark Arts',
        'Divination',
        'Muggle Studies',
        'History of Magic',
        'Transfiguration',
        'Potions',
        'Care of Magical Creatures',
        'Charms',
        'Flying'
    ]