## **Level 00 :**

On doit se loguer sur l’user flag00, qui lui a les droits d'executer getflag.

On a rien dans le home.

On va rechercher des fichiers qui aurait rappport avec cet user dans la machine:

```shell
find / -user "flag00" 2>/dev/null`
# /usr/sbin/john
# /rofs/usr/sbin/john
```

Les deux fichiers contiennent la meme chose: `cdiiddwpgswtgt`

Avec un simple rot15, on obtient: `nottoohardhere`

>  Password: nottoohardhere

>  Token: **x24ti5gi3x0ol2eh4esiuxias**