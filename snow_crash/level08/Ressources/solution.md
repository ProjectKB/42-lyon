
## **Level 08**

On a un script executable, ainsi qu'un fichier token, sur lequel nous n'avons pas de droits.

Le script prend en parametre un fichier, mais ne fonctionne pas si le fichier se nomme "token".

`chmod 777 .` < Pour pouvoir écrire dans le dossier courant.

On crée donc un lien symbolique avec un autre nom qui pointe vers le fichier `token`.

`ln -s token evil`, puis `./level08 evil`.

> Password : quif5eloekouj29ke0vouxean

> Token: **25749xKZ8L7DkSCwJkT9dyv6f**