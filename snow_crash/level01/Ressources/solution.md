
## **Level 01 :**

On a rien dans le home.

La meme commande find utilise precedemment ne donne rien avec flag01. Mais on sait que le fichier [/etc/passwd](https://fr.wikipedia.org/wiki/Passwd#Le_fichier_/etc/passwd) contient toutes les informations relatives aux utilisateurs (login, mots de passe, ...).

>Avant le masquage du mot de passe (c'est-à-dire dans les premières implantations de Unix), ce champ [le deuxième] contenait un hachage cryptographique du mot de passe de l'utilisateur (en combinaison avec un sel).

Ici, la ligne de l'user flag01 est: `flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`

On sait donc que `42hDRfypTqqnw` est un hash du mot de passe. On va utiliser le soft [john the ripper](https://fr.wikipedia.org/wiki/John_the_Ripper) pour le casser.

> Password : abcdefg

> Token: **f2av5il02puano7naaf6adaaf**