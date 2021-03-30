## Level 14:

Il n'y a **_absolument_** rien de présent dans le repo, on décide donc de casser getflag.

Pour se faire on le sort de la vm avec `scp -P 4242 level14@127.0.0.1:/rofs/bin/getflag your_destination`.

On le passe ensuite dans le soft [Cutter](https://cutter.re/) pour reverse le binaire.
On peut maintenant lire tout le programme en C où l'on peut remarquer que les tokens sont en fait encryptés à l'aide de la fonction `ft_des`.

```c
// [...]
} else {
    if (uVar4 == 0xbc4) {
        uVar5 = ft_des("8_Dw\"4#?+3i]q&;p6 gtw88EC");
        fputs(uVar5, uVar3);
    } else {
        if (uVar4 < 0xbc4) {
            uVar5 = ft_des("70hCi,E44Df[A4B/J@3f<=:`D");
            fputs(uVar5, uVar3);
        } else {
            if (uVar4 == 0xbc5) {
                uVar5 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
                fputs(uVar5, uVar3);
            } else {
                if (uVar4 != 0xbc6) goto code_r0x08048e06;
                uVar5 = ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
                fputs(uVar5, uVar3);
            }
        }
    }
}
// [...]
```

De là, il n'y a plus qu'à récupérer cette fonction et à l'appeler dans un main classique avec la dernière string à encrypter présente ci-dessus et le tour est joué.

```c

#include <string.h>
#include <unistd.h>
#include <stdio.h>

char * ft_des(char *src)
{
    char cVar1;
    char *pcVar2;
    uint32_t uVar3;
    char *pcVar4;
    unsigned char uVar5;
    char *var_2ch;
    uint32_t var_1ch;
    uint32_t var_18h;
    int32_t var_14h;
    int32_t var_10h;
    char *var_ch;
    
    uVar5 = 0;
    pcVar2 = (char *)strdup(src);
    var_18h = 0;
    var_1ch = 0;
    do {
        uVar3 = 0xffffffff;
        pcVar4 = pcVar2;
        do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + (uint32_t)uVar5 * -2 + 1;
        } while (cVar1 != '\0');
        if (~uVar3 - 1 <= var_1ch) {
            return pcVar2;
        }
        if (var_18h == 6) {
            var_18h = 0;
        }
        if ((var_1ch & 1) == 0) {
            if ((var_1ch & 1) == 0) {
                var_10h = 0;
                while (var_10h < "0123456"[var_18h]) {
                    pcVar2[var_1ch] = pcVar2[var_1ch] + -1;
                    if (pcVar2[var_1ch] == '\x1f') {
                        pcVar2[var_1ch] = '~';
                    }
                    var_10h = var_10h + 1;
                }
            }
        } else {
            var_14h = 0;
            while (var_14h < "0123456"[var_18h]) {
                pcVar2[var_1ch] = pcVar2[var_1ch] + '\x01';
                if (pcVar2[var_1ch] == '\x7f') {
                    pcVar2[var_1ch] = ' ';
                }
                var_14h = var_14h + 1;
            }
        }
        var_1ch = var_1ch + 1;
        var_18h = var_18h + 1;
    } while( 42 );
}


int main(void)
{
    printf("%s\n", ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"));
    return (0);
}

```

### Variante GDB

`gdb getflag`

On set 3 brakpoints:

`b main `; `b getuid`; `b ptrace`

`run` <- On lance le programme:

`c` <- On continue jusqu'a ptrace.

> ptrace est utilise ici pour faire fail gdb: comme c'est gdb qui gere l'execution de notre programme, ptrace ne peut pas fonctionner, il retourne -1.
getflags check cette valeur de retour et affiche "You_should_not_reverse_this"

`s` <- On passe sur l'instruction d'apres

`p $eax` <- On voit que eax a été set a -1.

`p $eax=0 `<- On le set a 0

`c` <- On continue jusqu'a `getuid()`

`s`  <- On step sur l'instruction suivante.

`p $eax` <- Retoure `2014`: On peut verifier dans `/etc/paswd` que 2014 est bien l'uid de l'user actuel: `level14`.

`p $eax=3014`  <- On set l'uid sur 3014, l'uid de l'user `flag14` (vu dans `/etc/passwd`)

`c` <=- on continue l'execution ...

$ Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ <- TADAM 🥳


> Token : **7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ**