## **Level 12:**

Le script perl donné, qui tourne sur le port **4646** fait un `egrep` avec un paramètre. Ce paramètre est donné par l’user en url, par exemple via curl.

Il est passé dans une serie de regex, une qui trim tout ce qui est après le premier espace, et l’autre qui fait un uppercase sur la string.

On a le droit d’ecrire dans `/tmp` , et on sait que `egrep` peut exec une commande dont il utiliseras le retour pour sa recherche. Ex: `egrep "$(echo coucou)"` cherche le pattern `coucou`.

On fait un script executable qui appelle `getflag` et met son retour dans` /tmp/flag.txt`. C'est ce script qui sera executé par `egrep`.

Reste le soucis de l’uppercase, en mettant le chemin` /tmp`, il se transformeras en `/TMP` et le script ne sera pas execute. On utilise donc le wildcard pour que grep “passe” tmp.

Enfin, on entoure notre string avec les backticks, pour que la string soit bien reconnue comme commande.

``localhost:4646?x="`/*/FOLDER/*`"``

avec le script dans : `/tmp/FOLDER/script.sh`

> Token : **g1qKMiRpXf53AWhDaU7FEkczr**