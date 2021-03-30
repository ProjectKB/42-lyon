## Level3

_Exploitation des failles format-strings._

Le programme lit 512 octets sur l’entrée standard puis print ce qu'il a lu sur `stdout`.
On voit que le buffer qui contient l’entrée est donné tel quel à `printf` sans passer par une string de formatage `%s`.

Pour exploiter cette faille on utilise l'indicateur de conversion `%n` qui écrit en mémoire le nombre de caractère que `printf` a écrit avant lui.

Exemple: `printf("AAAA%n", &var); //var = 4`

Sans paramètre, `printf` va chercher les valeurs qu'il trouve sur la pile et l'indicateur de conversion `%n` va écrire dessus.

Le caractère `$` permet de spécifier quel argument utiliser. Ainsi, `%4$d` cible le quatrième argument passé en paramètre à `printf`. De la même manière, si il n'existe pas, ce sera la quatrième valeur trouvée sur la pile (en partant du bas).

#### Solution:

On voit que la condition pour ouvrir le shell est que la variable globale `_m` soit égale à `64`.

On va donc passer l'adresse de `_m` pour que `%n` écrive dessus puis on écrit 60 "A" pour que la valeur écrite par `%n` soit bien:  `60 chars + les 4 chars de l'adresse de _m == 64`.

```cat <(python -c 'print("\x8c\x98\x04\x08" + "A"*60+"%4$n" )') - | ./level3```


## Ressources

- [hacktion.be](https://hacktion.be/format-strings/)
- [zenk-security](https://repo.zenk-security.com/Techniques%20d.attaques%20%20.%20%20Failles/Les%20failles%20Format%20String.pdf)
- [printf format](https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160)
