## Level0

On a un exécutable qui a les droits du `level1`. 

À l’exécution le binaire segfault si il n'a pas d'argument, sinon, il affiche "_no !_" et rend le main.

Avec gdb on remarque que le programme appelle `atoi` sur `argv[1]` et compare son résultat avec la valeur `0x1a7` (423).

Si elle est bonne, il appelle `execv` avec `/bin/sh` en paramètre et lance un shell.

#### Solution:

`./level0 423`

`$ cat /home/user/level1/.pass`

