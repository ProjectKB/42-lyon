## Level8

On a deux globales non initialisées: `service` et `auth`.

#### Commandes:

##### `auth`: `[auth param]` : 

Si un paramètre est donne , alloue 4 bytes et met l'adresse dans `auth`.

##### `service`: `[service param]`:

Fait un `strdup()` de son paramètre et met l'adresse de retour dans `service`. L'adresse de retour est 16 bytes après `auth` car `malloc()` alloue de façon consécutive avec du padding. Comme la mémoire n'est pas libérée, si on refait la commande, on se retrouve encore 16 bytes plus loin.

#### `login`: 

Check si il y a une valeur à `auth + 32`. Si oui, ouvre un Shell.

### Solution:

On initialise la variable `auth`. Le paramètre n'as aucune incidence ici.
`auth coucou` 

Retour: `>>> 0x86c6980, (nil)`

On initialise `service` avec un paramètre de 16 caractères. Avec la taille de `service`, on est donc 32 octets après `auth`.

`service abcdefghijklmno` *(15 chars + \n == 16)*

Retour: `>>> 0x9d1f980, 0x9d1f990`

login va check à `auth + 32` sur lequel on vient d’écrire un `\n` dans notre cas.

#### Variante:

On peut aussi faire la commande `service` deux fois sans paramètres.