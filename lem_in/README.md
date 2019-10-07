## LE PROJET EN LUI MÊME

Ce projet est une introduction à la problématique des algos de pathfinding.
<br> Il s'agit de trouver la meilleure solution possible pour relier un point A à un point B jalonné de plusieurs étapes ou non.

Le fichier que l'on fera lire par notre programme décrit une fourmilière caractérisée par :
* Son nombre de fourmis
* Ses salles
* Les liaisons entre ces salles

Au premier tour toutes les fourmis sont présentes dans la salle `start`, si la fourmilière transmise est valide le programme s'arrête quand toute les fourmis ont atteint la salle `end`.
<br>Il ne peut y avoir qu'une fourmi par salle et elles ne peuvent se déplacer que d'une salle par tour.

Pour une meilleure compréhension, voici un descriptif du type de fichier (la fourmilière) à passer en argument au programme : 

<img src="img/demo_file.png" width="70%">

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
* Sinon, `ERROR` sera affiché sur la sortie standard

## CAS D'UNE FOURMILIÈRE VALIDE

Dans ce cas, le programme imprimera en premier le contenu du fichier exploité, suivit des déplacements des fourmis (une ligne correspondant à un tour).

Exemple de déplacements réalisés par les fourmis (la description de la fourmilière n'est pas présente pour des soucis de lisibilité mais est disponible <a href="map_tmp">ici</a>) : 

<img src="img/ants_output.png" width="70%">

