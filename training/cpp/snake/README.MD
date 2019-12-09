### LE PROJET EN LUI MÊME

Petit projet personnel consistant à créer un snake multijoueur.
L'idée était de prendre en compétence sur **C++**, la **POO** et de découvrir une nouvelle librairie graphique : **Ncurses**.

On peut donc en pratique jouer de 1 à 4 et il est en théorie possible d'ajouter jusqu'à un nombre x de participants il suffit d'implémenter plus d'objets `Snake`.

Un objet `Snake` se déclare comme suit :

`Snake random(Window &window, {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT}, associated_color);`

Les fonctionnalitées implémentées sont les suivantes :
* Traverser d'un extrême de l'écran à son opposé (de x_max à x_min et inversement)
* Gain d'une pièce pour chaque objectif mangé (les 'x')
* Manger les partie du snake d'autre joueur (pas de gain de pièce pour autant)
* Réduction du temps d'affichage des frames en fonctions du nombre d'objectif obtenu
* Quitter le jeu à l'aide de la touche `ESC`

Le projet se compile à l'aide de `Make`.

Voici quelques extraits de partie pour illustration :


