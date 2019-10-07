## LE PROJET EN LUI MÊME

Ce projet avait pour but de nous introduire à la lecture de fichier et aux variables statiques.

Nous devions implémenter une fonction prototypée comme suit : `int get_next_line(const int fd, char **line)` permettant de stocker une ligne dans `**line` d'un fichier texte passé en paramètre (la fin d'une ligne étant déterminée par un `'\n'` ou un `EOF`).
<br>La tête de lecture du fichier sera déplacée à chaque iteration de la fonction à l'aide de la variable statique.
<br>Il nous était également demandé d'implémenter un buffer de lecture variable.

## BONUS

Gérer les multi-files descriptor (pouvoir lire plusieurs fichier en même temps).
