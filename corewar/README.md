## LE PROJET EN LUI MÊME
* C’est quoi, le Corewar ?
  * Le Corewar est un jeu très particulier. Il consiste à rassembler autour d’une "machine virtuelle" des "joueurs", lesquels vont y charger des "champions" qui vont se
battre à l’aide de "processus", dans le but, entre autres, de faire en sorte qu’on dise
d’eux qu’ils sont "en vie".
  * Les processus s’exécutent séquentiellement au sein de la même machine virtuelle,
et du même espace mémoire. Ils peuvent donc, entre autre chose, s’écrire les uns
sur les autres afin de se corrompre mutuellement, de forcer les autres à exécuter
des instructions qui leur font du mal, de tenter de recréer à la volée l’équivalent
logiciel d’un Côtes du Rhône 1982, etc ...
  * Le jeu se termine quand plus aucun processus n’est en vie. À ce moment là, le
gagnant est le dernier joueur à avoir été rapporté comme étant "en vie".

* Le projet consiste à rendre trois parties distinctes :
  * L’assembleur : C’est le programme qui va compiler vos champions et les traduire
du langage dans lequel ils sont écrits (l’assembleur) vers un "bytecode", à
savoir un code machine qui sera directement interprété par la machine virtuelle.
  * La machine virtuelle : C’est l’"arène" dans laquelle les champions vont s’exécuter.
    Elle offre de nombreuses fonctionnalités, toutes utiles au combat des champions.
    Il va de soi qu’elle permet d’exécuter plusieurs processus en simultané.
  * Le champion : Il nous est également demandé d'écrire un champion capable de battre un des champions de base fournis dans les ressources du sujet, démontrant ainsi que nous avons compris le fonctionnement basique de ce dernier.
<br><br>
## L'ASSEMBLEUR

* Notre machine virtuelle va exécuter du code machine (ou "bytecode"), qui devra
être généré par notre assembleur. L’assembleur (le programme) va prendre en
entrée un fichier écrit en assembleur (le langage), et sortir un champion qui sera
compréhensible par la machine virtuelle.
* Il se lance de la façon suivante : `./asm monchampion.s`.
* Il va lire le code assembleur à traiter depuis le fichier .s passé en paramètre, et
écrire le bytecode résultant dans un fichier nommé comme l’entrée en remplaçant
l’extension .s par .cor .
* En cas d’erreur, nous devrons afficher un message pertinent sur la sortie d’erreur,
et ne pas produire de fichier .cor
<br><br>
## LA VM
  
* Chaque processus aura à sa disposition les éléments suivants, qui lui sont propres :
  * REG_NUMBER registres qui font chacun une taille de REG_SIZE octets.
Un registre est une petite "case" mémoire, qui ne contient qu’une seule valeur.
  * Un PC ("Program Counter"). C’est un registre spécial, qui contient juste l’adresse,
dans la mémoire de la machine virtuelle, de la prochaine instruction à décoder et exécuter.
  * Un flag nommé carry, qui vaut 1 si la dernière opération a réussi. Seules
certaines opérations vont modifier le carry.
  * Le numéro du joueur est généré par la machine ou spécifié au lancement, et est
fourni aux champions via le registre r1 de leur premier processus au démarrage.
Tous les autres registres sont mis à 0. Sauf le PC.
  * Les champions sont chargés en mémoire de façon à espacer équitablement leurs
points d’entrée.
  * La machine virtuelle va créer un espace mémoire dédié au combat des joueurs, puis
y charger les champions et leurs processus associés, et les exécuter séquentiellement
jusqu’à ce que mort s’ensuive.
  * Tous les CYCLE_TO_DIE cycles, la machine doit s’assurer que chaque processus
a exécuté au moins un live depuis la dernière vérification. Un processus qui ne se
soumet pas à cette règle sera mis à mort.
  * Si au cours d’une de ces vérifications on se rend compte qu’il y a eu au moins
NBR_LIVE exécutions de live depuis la dernière vérification en date, on décrémente CYCLE_TO_DIE de CYCLE_DELTA unités.
  * Quand il n’y a plus de processus en vie, la partie est terminée.
  * Le gagnant est le dernier joueur qui a été rapporté comme étant en vie. La machine va ensuite afficher : "le joueur x(nom_champion) a gagne", où x est le numéro
du joueur et nom_champion le nom de son champion.
  * A chaque exécution valide de l’instruction live, la machine doit afficher :
"un processus dit que le joueur x(nom_champion) est en vie"
  * En tout état de cause, la mémoire est circulaire et fait MEM_SIZE octets.
  * En cas d’erreur, vous devrez afficher un message pertinent sur la sortie d’erreur.
  * Si on n’a pas décrémenté CYCLE_TO_DIE depuis MAX_CHECKS vérifications,
on le décrémente.
  * Au bout de nbr_cycles cycles d’exécution, dump la mémoire sur la sortie standard, puis quitte la partie. La mémoire doit être dumpée au format hexadécimal,
avec 32 octets par ligne.
  * Les champions ne peuvent pas dépasser CHAMP_MAX_SIZE, sinon c’est une
erreur.
<br><br>
## LE LANGAGE ET LA COMPILATION

* Le langage assembleur
  * Le langage assembleur est composé d’une instruction par ligne.
  * Une instruction se compose de trois éléments : Un label (optionnel), composé
d’une chaîne de caractères parmi LABEL_CHARS suivi par LABEL_CHAR ; un
opcode ; et ses paramètres, séparés par SEPARATOR_CHAR. Un paramètre peut
être de trois types :
  * Registre : (r1 <–> rx avec x = REG_NUMBER)
  * Direct : Le caractère DIRECT_CHAR suivi d’une valeur numérique ou d’un
label (précédé par LABEL_CHAR), ce qui représente une valeur directe.
  * Indirect : Une valeur ou un label (précédé de LABEL_CHAR), ce qui représente la valeur qui se trouve à l’adresse du paramètre, relativement au PC du
processus courant.
  * Un label peut n’avoir aucune instruction à sa suite, ou être placé sur la ligne
d’avant l’instruction qu’il concerne.
  * Le caractère COMMENT_CHAR démarre un commentaire.
  * Un champion comportera également un nom et une description, qui sont présents
sur une ligne après les marqueurs NAME_CMD_STRING et COMMENT_CMD_STRING.
  * Tous les adressages sont relatifs au PC et à IDX_MOD sauf pour lld, lldi et
lfork.
  * Le nombre de cycles de chaque instruction, leur représentation mnémonique, leur
nombre de paramètres et les types de paramètres possibles sont décrits dans le
tableau op_tab déclaré dans op.c. Les cycles sont toujours consommés.
  * Tous les autres codes n’ont aucune action a part passer au suivant et perdre un
cycle.

* Les instructions 

<img src="corewar/img/instructions_tab.jpg">
<br>

## BONUS

<img width="100%" src="corewar/img/usage.png">

### Partie Graphique

Pour ce projet nous avons mis en place 3 modes d'affichages à l'aide la SDL :
<br><br>
<div> 
  <img width="100%" src="corewar/img/game_on.gif">
  <img width="100%" src="corewar/img/light.gif">
  <img width="100%" src="corewar/img/responsive.gif">
</div>

<br>
Nous avons également implémenté la possibilité d'afficher des animations au début et à la fin de chaque partie (optionnelle).
<br><br>
<div> 
  <img width="100%" src="corewar/img/start.gif">
  <img width="100%" src="corewar/img/end.gif">
</div>

<br><br>

### DSM

Vous trouverez à la racine du projet un désassembleur de fichier `.cor` qui vous recréera le fichier `.s` correspondant.
Vous pourrez le tester à l'aide de : `./dsm votre_fichier.cor`.
<br><br>
### SCRIPTS

Trois scripts ont été implémentés pour créer des champions :
* Un générateur de champion aléatoire : `sh ./script/champion_generator.sh`.<br>
Un fichier `Random_Commodore.s` sera ajouté dans `ressource/source/` et un `Random_Commodore.cor` dans `ressource/compile/`.
* Un générateur de champion battant à coup sûr le champion passé en paramètre : `sh ./script/beat_champion <champ_to_beat.cor>`.<br>
Un fichier `ChampToBeat_Nemesis.s` sera ajouté dans `ressource/source/` et un `ChampToBeat_Nemesis.cor` dans `ressource/compile/`.
* Un améliorateur de champion qui fera jouer un champion passé en premier paramètre contre des joueurs générés aléatoirement jusqu'à ce qu'un de ces joueurs arrivent à battre votre joueur.
Il vérifiera également que ce champion arrive à battre à minima les mêmes champions que le votre.
Si c'est le cas `Darwin.s` et un `Darwin.cor` seront ajoutés aux mêmes endroits que précédemment sinon le script continuera simplement à boucler.
Ce script ce test à l'aide de `sh ./script/train_champion.sh <your_champ.cor>`





