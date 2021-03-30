# Bonus3

Le programme doit prendre exactement 1 argument, qui sera ensuite transformé par `atoi`.
Ensuite, le fichier `"/home/user/end/.pass"` est lu dans un tableau ,disons `tab`, qui va être modifié à l'index de la valeur renvoyée par `atoi`.

`tab` va être comparé à l'argument grâce à `strcmp`. Notre première valeur de `tab` doit être égale à 0 pour être équivalent à l'argument.

En passant une string vide `""` en argument, `atoi` va retomber 0 et donc placer un 0 dans `tab[0]`.
La comparaison se fera donc entre une string vide et notre argument.