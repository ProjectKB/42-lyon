# LEVEL03

## Decryptage

Dans le code C on voit que:

- Sous certaines conditions, on rentre dans la fonction `decrypt()` qui contient un `system();`, nous permettant de lancer un shell.

- `decrypt()` se lance avec une valeur aléatoire si
    
        322424845 - argument

    n’est pas  entre `0x0` et `0x9` ou entre `0x10` et `0x16`.

- On utilise `322424827` comme argument pour rentrer dans `decrypt()` avec `322424845 - 322424827` = `18`

- Dans `decrypt()`, deux strings sont écrites en dur, “Congratulations” et “Q}|u'sfg~sf{}|a3”.  Le programme applique un XOR sur chaque caractères de la string avec notre argument (18), devant transformer la chaîne crypte en `Congratulations`
  

## Solution

```c
int main()
{
    char *s = "Q}|u`sfg~sf{}|a3";

    for (int i = 0; i < strlen(s); ++i)
    {
        printf("%c", s[i] ^ 18 );
    }
    return 0;
}

$ Congratulations!
```

```bash
./level03
```
Password: 322424827

>> kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf