# LEVEL00

## Faille

Le programme va prendre un argument par l'intermédiaire d'un `scanf`, si il est égale à 0x149C un **shell** est lancé.

## Solution

    0x149C = 5276

On envoie donc cette valeur dans `stdin`

>> uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL