### LE PROJET EN LUI MÊME

Fillit est un projet nous permettant de decouvrir et/ou de nous familiariser avec
une problematique récurrente en programmation : la **recherche d’une solution optimale
parmi un très grand nombre de possibilités, dans un délai raisonable**. Dans le cas de ce
projet, il s’agira d’agencer des Tetriminos entre eux et de déterminer le plus petit carré
possible pouvant les acueillir.

Un Tetriminos est une figure géométrique formée de 4 blocs que vous connaissez
grâce au célèbre jeu Tetris.

<img src="fillit/ressources/tetriminos.png" width="300">

Ce projet est aussi un prétexte pour nous donner une application basique au backtracking.
<br><br>
### LANCER LE PROJET

Pour compiler le projet une fois le repo téléchargé sur votre machine vous aurez juste à utiliser `make`.

Vous l'exécuterez à l'aide de `./fillit vos_tetriminos`

Le fichier `vos_tetriminos` contient une liste de tetriminos que l'algorithme de backtracking devra ordonner.

<img src="fillit/ressources/random_pieces.png" width="300">

Pour générer un fichier aléatoire de tétriminos vous trouverez un générateur dans le dossier `ressources` 
qui créera un fichier `random_pieces` à la racine du projet.

Pour générer ce fichier vous aurez à utiliser la commande `./ressources/random_pieces.sh`.
<br><br>
### BONUS

La sortie donnée par le programme est l'état final de la map contenant les tétriminos sur la sortie standard.

<img src="fillit/ressources/classic.png" height="300">
<br>
Nous avons choisis d'implémenter trois type d'affichage supplémentaires :
<br><br>

* Un mode coloré pour mieux distingué les différentes pièces, utiliser `make re GRAPHIC=yes`.

<img src="fillit/ressources/color.png" height="300">
<br>

* Le même mode avec une option "step by step" pour bien visualiser le fonctionnement de l'algorithme,<br>utiliser `make re GRAPHIC=step`.

<img src="fillit/ressources/demo.gif" height="300">
<br>

* Un mode composé d'unicode pour le plaisir, utiliser `make re GRAPHIC=crazy`.

<img src="fillit/ressources/crazy.png" height="300">
