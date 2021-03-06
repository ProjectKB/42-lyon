## LE PROJET EN LUI MÊME

Ce projet est une introduction à la problématique des algos de pathfinding et aux parcours de graphes.

Il s'agit de trouver la meilleure solution possible pour relier une salle `START` à une salle `END`.<br>
Ces salles peuvent être reliés par un nombre X d'autres salles et doivent être parcourues par un nombre Y de fourmis.<br>
Il ne peut y avoir qu'une fourmi par salle (sauf pour `start` et `end`) et elles ne peuvent se déplacer que d'une salle par tour.<br>
Au premier tour toutes les fourmis sont présentes dans la salle `start`, si la fourmilière transmise est valide le programme s'arrête quand toute les fourmis ont atteint la salle `end`.

Le fichier descriptif de la fourmilière est caractérisé par :
* Son nombre de fourmis
* Ses salles
* Les liaisons entre ces salles

Pour une meilleure compréhension, voici un exemeple de fourmilière valide : 

<img src="img/demo_file.png" width="70%"><br><br>

## CAS D'UNE FOURMILIÈRE PARTIELLEMENT/COMPLÈTEMENT INVALIDE

Ce fichier peut être invalide pour différentes raisons :
* Fichier invalide (problème de droit, pas un fichier texte...)
* Il manque le nombre de fourmis/la description des salles/les liaisons
* Il n'y a aucun chemin permettant de relier les salle `start` et `end`
* Les salles `start`/`end` ne sont pas présentes

Dans ces cas, `ERROR` sera imprimé sur la sortie standard.

Si une ligne de la fourmilière n'est pas valide, à savoir :
* Une commande (##something) n'étant pas suivi de `start` ou `end`
* La répétition d'une commande valide déja fournit, d'une salle, ou d'une liaison
* Tout autre chose qui n'a rien a faire là

Deux cas de figure sont possibles :

* Si les informations précédents cette ligne fournissent une fourmilière valide, on la traite telle quelle et on ignore le reste du fichier à partir de cette ligne
* Sinon, `ERROR` sera affiché sur la sortie standard.<br><br>

## CAS D'UNE FOURMILIÈRE VALIDE

Dans ce cas, le programme imprimera en premier le contenu du fichier exploité, suivit des déplacements des fourmis (une ligne correspondant à un tour).

Les déplacements des fourmis sont exprimés comme suit (L`numéro de fourmi`-`nom de salle`) :<br>
* 1er tour | `L1-salleA L2-salleB L3-salleC`<br>
* 2e  tour | `L1-salleD L2-salleE L3-salleF`
<br>... etc jusqu'à ce que toute les fourmis soient arrivées à bon port.

Exemple de déplacements réalisés par les fourmis (la description de la fourmilière n'est pas présente pour des soucis de lisibilité mais est disponible <a href="map_tmp">ici</a>) : 

<img src="img/ants_output.png" width="70%">

Il est important de comprendre que notre algorithme nous fournira dans la plupart des cas un nombre de chemins valides supérieurs à celui dont nous aurons réellement besoin.

Imaginons que l'on trouve 5 chemins empruntables, qu'on ai 5 fourmis à placer et que les 3 premiers chemins ne requiert que 2 coups alors que les 2 restant nécessitent 4 coups.

On pourrait choisir d'utiliser tout les chemins mais on serait alors moins efficace qu'en utilisant seulement les 3 premiers chemins. En effet, dans le premier cas il nous faudrait 4 coups pour placer toute les fourmis contre 3 pour le second.<br><br>

## ALGO ET OPTIMISATION

Pour réussir au mieux ce projet nous avions deux problématiques à concilier, le fait d'avoir un algo nous permettant de trouver le plus de chemins cours sans intersection entre eux et le fait d'avoir un algo le plus rapide possible.

Nous avons donc choisis d'implémenter <a href="https://fr.wikipedia.org/wiki/Algorithme_A*">l'algorithme A*<a/> offrant un bon équillibre entre ces deux problématiques et de faire nos parcours de chemin pour la résolution à travers une <a href="https://fr.wikipedia.org/wiki/Matrice_d%27adjacence">matrice d'adjacence<a/> offrant ainsi la possibilitée d'utiliser des opérateurs binaires et d'allouer la mémoire au bit prêt et donc d'obtenir un gain de temps considérable.<br><br>

## COMPILATION ET BONUS

Le projet se compile à l'aide de `make` et est exécuté comme suit : `./lem-in < your_map`.

Un générateur de map nous est fournit au commencement du projet, nous avons implémenté un script pour chaque type de map possible (chacun d'eux vous créera une `map_tmp` à la racine du projet) :
* `./tools/fl-1` générera une map avec 1 fourmi
* `./tools/fl-10` générera une map avec 10 fourmis
* `./tools/fl-100` générera une map avec 100 fourmis
* `./tools/big` générera une map avec beaucoup de fourmis et beaucoup de salles
* `./tools/big-s` idem que pour les `big` mais avec énormément d'inter connexion entre les salles

Ces scripts produiront la sortie suivante :

<img src="img/script_output.png" width="40%">

Où l'on peut voir dans l'ordre :
* en bleu le nombre de tour nécessaire à notre programme pour placer toute les fourmis
* en magenta la différence avec la recommandation donnée par le générateur de map
* en vert `GOOD` si le résultat est égal/inférieur à la recommandation ou en rouge `FALSE` dans le cas contraire
* le temps prit par le programme
* le nombre de fourmis présentes dans la fourmilière
* la recommandation du nombre de tour nécessaire pour placer toute les fourmis
