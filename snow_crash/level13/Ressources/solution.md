## Level 13:

On a un executable qui nous print "UID 2013 started us but we we expect 4242".

Le programme se lance sur l’uid envoye par la fonction `getuid()`. On va créer notre propre fonction getuid pour lui faire renvoyer la valeur 4242.

Pour cela, on compile la fonction suivante en librairie dynamique, a l’aide des flags `-shared -fPIC`.

On passe, avant l’exec de `./level13`, la variable d’enviroonement `LD_PRELOAD` sur le cehmin de notre lib, ce qui force le linker a utiliser notre fonction

```c
// getuid.c :
#include <unistd.h>

uid_t getuid(void) { return 4242; }
```

`gcc -shared -fPIC -o /tmp/lib.so`

`LD_PRELOAD=/tmp/lib.so ./level13`

> token : **2A31L79asukciNyi8uppkEuSx**