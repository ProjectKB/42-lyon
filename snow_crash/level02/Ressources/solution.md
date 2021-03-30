## **Level 02 :**

On a juste un fichier: `level02.pcap`

pcap (« packet capture ») est une interface de programmation permettant de capturer un trafic réseau, qui permet aussi de sauvegarder les paquets capturés dans un fichier.

On peut l'ouvrir directement dans la vm avec par exemple `tcpdump -vr level02.pcap`, mais cela ne donne pas d'info intéressantes.

on va essayer dans Wireshark, qui est un soft tres utilisé dans ces cas.

On sort le fichier de la VM: `scp -P 4242 level02@127.0.0.1:/home/user/level02/level02.pcap .`.

Dans wireshark: click droit -> follow -> tcp stream -> `ft_wandr...NDRel.L0L`

> Password:  ft_waNDReL0L

> Token: **kooda2puivaav1idi4f57q8iq**
