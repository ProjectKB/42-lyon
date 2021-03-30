## **Level 11:**

On un script lua qui tourne sur 5151.

La fonction ` client:receive()` est la seule qui nous permet de rentrer quelque chose dans le programme. Or, le programme nous demande un password, on en deduit que c'est l'input du password qui sera transmit. On voit aussi que cette fonction set deux variables.

On entre le password apres avoir fait: `nc 127.0.0.1 5151`

En testant `Password: getflag > tmp/evil.txt` , `evil.txt` contient la string: "getflag".

On va essayer avec le deuxieme param:

`Password: bullshit ; Password: getflag > tmp/evil.txt` , cette fois, getflag est executé, et `evil.txt` contient le token.

> Token : **fa6v5ateaw21peobuub8ipe6s**