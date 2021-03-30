# LEVEL06

## **Code**

En exécutant le programme, on nous demande de rentrer un `login` puis un `serial`.

Un **shell** est lancé si le retour de la fonction `auth` vaut 0, cette fonction crypte le `login` puis le compare après transformation avec `serial`.

Si ils sont équivalent, elle renvoie 0.
___
## **Solution**

Nous avons retranscrit la partie cryptage de la fonction `auth` en lui donnant la string **bonjour** :

```c
#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int size;
    int login_crypted;

    char login[] = "bonjour";

    i = -1;
    size = strnlen(login, 32);
    login_crypted = (login[3] ^ 0x1337U) + 0x5eeded;
    while (++i < size)
    {
        if (login[i] < ' ')
            return 1;
        login_crypted = login_crypted + (login[i] ^ login_crypted) % 0x539;
    }
    printf("%d\n", login_crypted);
    return 0;
}
```

```bash
$> gcc encrypt.c ; ./a.out
6233767
```

Il ne reste plus qu'à utiliser ce nombre comme `serial` :

```bash
$> cat <(python -c 'print("bonjour")' ; python -c 'print("6233767")') - | ./level06
```

>> GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8