## **Level 03 :**

Le binaire `level03` present dans le home de l’user level03 fait un call a la fonction `system()`, avec `“/usr/bin/env echo exploit me”`

Utiliser` /usr/bin/env echo` permet d'utiliser la variable PATH pour trouver le chemin d'un exec. Ca permet  d'eviter de devoir faire des chemin absolus vers par exemple `/bin/echo`.

En faisant un lien symbolique de `echo` vers `/bin/getflags`, le programme va lancer `getflags` a la place d’`echo`, et avec les bons droits.

- On chmod le dossier courant pour pouvoir créer un lien symbolique. Puis ` ln -s /bin/getflag echo`
- `export PATH=.:$PATH` : On ajoute le dossier courant (avec not symlink) aux paths d'executables.
- `getflag`:

> Token: **qi0maab88jeaj46qoumi7maus**