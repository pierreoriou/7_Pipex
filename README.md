# PIPEX

#### TABLE DES MATIERES
- [I.  COMPRENDRE PIPEX](#i-comprendre-pipex)
- [II. CODER PIPEX](#ii-coder-pipex)

---

### I.	COMPRENDRE PIPEX
__
#### A. Objectifs du projet
__
Créer un programme qui recréé le comportement de la commande shell :

    < file1 cmd1 | cmd2 > file2

- _file1_ et _file2_ sont des <ins>fichiers</ins>.
- _cmd1_ et _cmd2_ sont des <ins>commandes shell</ins>.

#### B. Qu'est-ce qu'une commande ?
__
Une commande, dans le contexte des systèmes d'exploitation de type Unix, est essentiellement <ins>un programme exécutable qui peut être appelé depuis le terminal</ins> ou depuis un script shell. Lorsqu'une commande est exécutée dans un terminal Unix, des arguments sont souvent fournis à cette commande pour spécifier son comportement ou les données sur lesquelles elle doit agir.
<ins>La "standard input" (stdin ou entrée standard) d'une commande est la source de données à partir de laquelle cette commande lit.</ins> Par défaut, dans un terminal, l'entrée standard d'une commande est associée au clavier. Ainsi, lorsque vous tapez quelque chose dans un terminal et appuyez sur Entrée, ce que vous tapez devient l'entrée standard pour la commande en cours d'exécution.
Enfin, <ins>la "standard output" (stdout ou sortie standard) est l'endroit où la commande écrit ses résultats.</ins> Ces entrées et sorties peuvent être redirigées vers différents flux, tels que des fichiers, d'autres commandes (via des pipes), ou le terminal lui-même.

#### C. Fonctionnement de la commande < file1 cmd1 | cmd2 > file2
__
Prenons l'exemple de la commande ci-dessous et décrivons son comportement précis.

    < infile grep a1 | wc -w > outfile

1. __< infile__ redirige le contenu du fichier <ins>infile</ins> vers l'entrée standard de la commande suivante qui est <ins>grep a1</ins>. _Cela signifie que grep a1 utilisera le contenu de infile comme entrée._

2. __grep a1__ filtre les lignes qui contiennent le motif "a1". Elle ne va traiter que les lignes de <ins>infile</ins> qui contiennent "a1".

3. __|__ : L'opérateur de pipeline transmet la sortie de grep a1 à wc -w.

4. __wc -w__ : Cette commande compte le nombre de mots dans son entrée, _c'est-à-dire le nombre de mots contenant "a1" dans infile_.

5. __> outfile__ : La sortie de wc -w (le nombre de mots contenant "a1" dans infile) est redirigée vers le fichier <ins>outfile</ins>. Si le fichier <ins>outfile</ins> n'existe pas, il est créé ; s'il existe déjà, son contenu est remplacé par la sortie de la commande.

<ins>Concrêtement</ins>, si infile contient le texte suivant :
>a1 b1 c1
a2 b2 c2
a3 b3 c3

Alors grep a1 filtrera les lignes qui contiennent "a1", qui sont :
>a1 b1 c1

Ensuite, wc -w comptera le nombre de mots dans cette ligne, ce qui donnera "3", car il y a trois mots dans la ligne.

Ainsi, outfile contiendra "3", car c'est le nombre de mots dans les lignes contenant "a1" dans infile.

#### D. Attention aux contextes particuliers
__
Prenons l'exemple de la commande ci-dessous et décrivons son comportement précis.

    < infile ls -l | wc -l > outfile

La commande ls -l affichera le même résultat, qu'il soit précédé de < infile ou non. Cela est dû au fait que ls -l ne prend pas en compte son entrée standard (stdin) ; <ins>il se contente de lister les fichiers et répertoires dans le répertoire courant</ins>.

Le fait d'inclure < infile avant ls -l a pour effet de rediriger le contenu du fichier infile vers l'entrée standard de ls -l. Cependant, ls -l n'utilise pas cette entrée standard, il ne fait référence qu'au répertoire courant.

Ainsi, dans ce cas précis, l'utilisation de < infile est superflue car elle n'affecte pas la sortie de ls -l. La commande ls -l affichera toujours le contenu du répertoire courant, qu'il y ait une redirection d'entrée ou non.

#### E. Les nouvelles fonctions autorisées
__
- __access__ : Cette fonction vérifie si le processus appelant peut accéder à un fichier (si le fichier existe et si le processus a les permissions appropriées pour le lire, l'écrire ou l'exécuter).

> __#include <unistd.h>__
__int access(const char *pathname, int mode);__

> __MAN ACCESS__ : access()  checks  whether  the  calling process can access
the file pathname. If pathname is a symbolic link, it is dereferenced.
The mode specifies the accessibility check(s) to be performed,
and is either  the value  F_OK, or a mask consisting of the bitwise OR
of one or more of R_OK, W_OK, and X_OK.  F_OK tests for the existence
of the file.  R_OK, W_OK, and  X_OK  test whether  the file exists and
grants read, write, and execute permissions, respectively.

> __RETURN VALUE__
_<ins>On  success</ins>  (all requested permissions granted, or mode is F_OK and
the file exists), <ins>zero is returned</ins>_.

><ins>On error</ins> (at least one bit in mode asked for a  permission  that  is denied, or
mode is F_OK and the file does not exist, or some other error occurred), <ins>-1 is
returned, and errno is set appropriately</ins>.

- __dup__ : Cette fonction duplique un descripteur de fichier ouvert, créant ainsi un nouveau descripteur de fichier qui se réfère à la même description de fichier ouverte.

- __dup2__ : Similaire à dup, dup2 duplique un descripteur de fichier ouvert mais permet de spécifier le numéro de descripteur de fichier désiré pour la duplication.

- __execve__ : Cette fonction remplace l'image du processus actuel par une nouvelle image de processus spécifiée par le chemin vers un fichier exécutable. Elle charge et exécute un nouveau programme dans l'espace de processus actuel.

- __fork__ : Cette fonction crée un nouveau processus (processus enfant) en dupliquant le processus appelant (processus parent). Après un fork réussi, deux processus sont créés - le parent et l'enfant - qui continuent l'exécution à partir du point d'appel du fork.

- __pipe__ : Cette fonction crée un tube (pipe), qui est un canal de communication unidirectionnel permettant à la sortie d'un processus d'être utilisée en tant qu'entrée d'un autre processus.

- __unlink__ : Cette fonction supprime un nom du système de fichiers. Si le nom est le dernier lien vers le fichier et qu'aucun processus n'a le fichier ouvert, le fichier est supprimé et l'espace qu'il occupait est libéré.

- __wait__ : Cette fonction permet au processus appelant d'attendre qu'un de ses processus enfants se termine. Si un processus enfant s'est déjà terminé au moment où la fonction wait est appelée, elle retourne immédiatement.

- __waitpid__ : Cette fonction est similaire à wait, mais permet au processus appelant d'attendre un processus enfant spécifique spécifié par son identifiant de processus (PID). Elle offre plus de contrôle sur le processus enfant à attendre.

#### F. L'enjeu majeur : la manipulation de processus
__
_Qu'est-ce qu'un processus ?_

Un processus en C est une instance d'un programme en cours d'exécution sur un système d'exploitation. Chaque processus possède sa propre mémoire, son propre espace d'adressage, ses variables et ses instructions d'exécution. Les processus sont la manière dont le système d'exploitation isole et gère l'exécution des différents programmes sur l'ordinateur.

Voici quelques caractéristiques clés des processus en C :

- __Isolation de la mémoire__ : Chaque processus possède son propre espace d'adressage virtuel isolé des autres processus. Cela signifie que les variables et les données d'un processus ne sont pas accessibles directement par un autre processus, à moins qu'ils ne partagent explicitement une région de mémoire (par exemple, en utilisant la mémoire partagée).

- __Contexte d'exécution__ : Chaque processus possède son propre contexte d'exécution, qui comprend les valeurs des registres de processeur, le pointeur d'instruction (program counter), et d'autres informations nécessaires pour l'exécution du programme.

- __Indépendance des ressources__ : Les processus sont indépendants les uns des autres en termes de ressources telles que les fichiers ouverts, les descripteurs de fichiers, les signaux, etc. Chaque processus gère ses propres ressources de manière isolée.

- __Création et gestion par le système d'exploitation__ : Les processus sont créés et gérés par le système d'exploitation. Le système d'exploitation alloue les ressources nécessaires à chaque processus, les planifie pour l'exécution sur le processeur et les termine une fois qu'ils ont terminé leur tâche.

#### G. Autres enjeux
__
Outre la manipulation de processus, les aspects importants du projet sont :

- __Gestion des fichiers__ : La manipulation correcte des fichiers est essentielle, y compris l'ouverture, la lecture, l'écriture et la fermeture des fichiers impliqués dans le processus. Cela comprend également la gestion des erreurs liées à l'accès ou à la manipulation des fichiers.

- __Gestion des erreurs__ : La gestion des erreurs est cruciale pour assurer la fiabilité et la robustesse du programme. Il est important de détecter et de gérer correctement les erreurs qui peuvent survenir lors de l'exécution du programme, telles que les échecs d'allocation de mémoire, les erreurs de lecture/écriture de fichiers, etc.

- __Traitement des arguments de ligne de commande__ : Le programme doit être capable de lire et d'interpréter correctement les arguments passés en ligne de commande, tels que les noms de fichiers et les commandes à exécuter. Cela implique de valider les arguments, de les interpréter correctement et de les utiliser dans le fonctionnement du programme.

- __Gestion des processus enfants__ : Une fois que les processus enfants sont créés pour exécuter cmd1 et cmd2, il est important de gérer leur cycle de vie, notamment en s'assurant qu'ils se terminent correctement et en récupérant leur statut de sortie.

- __Communication inter-processus__ : Les processus enfants doivent être capables de communiquer entre eux, en particulier pour transmettre la sortie de cmd1 à l'entrée de cmd2. Cela implique souvent l'utilisation de tubes (pipes) pour établir une communication bidirectionnelle entre les processus.

- __Gestion des ressources système__ : Le programme doit être conçu de manière à utiliser efficacement les ressources système telles que la mémoire, le processeur et les descripteurs de fichiers. Cela comprend la libération des ressources une fois qu'elles ne sont plus nécessaires pour éviter les fuites de mémoire ou les ressources non fermées.

---
### II.	CODER PIPEX
__
#### A. Parsing ou traitement des arguments des lignes de commandes.
__
__GENERAL :__
[x] Argc doit être 5.

__FILE 1 :__
[x] L'argument 1 ne doit pas être une chaine de caractères vide.
[x] L'argument 1 ne doit pas être une chaine contenant que des espaces.
[x] L'argument 1 ne doit contenir que des caracteres autorisés.
[x] L'argument 1 ne doit pas contenir plus de 255 caractères.
[x] L'argument 1 doit être un chemin de fichier ou dossier existant.
[x] L'argument 1 doit être le chemin d'un fichier et non d'un dossier.
[x] L'argument 1 doit avoir la permission READ.

__FILE 2 :__
[ ] L'argument 4 doit être un nom de fichier ou document ou un chemin, et qui doit être créé s'il n'existe pas.
[ ] L'argument 4, s'il existe déjà, doit être un fichier et non un dossier.
[ ] Si un dossier du nom de l'argument 4 existe, peut-être créer un fichier.
[ ] Le contenu de l'argument 4 doit être vérifié pour savoir s'il faut écrire dedans.

__COMMANDS :__
[ ] Les arguments 2 et 3 doivent être des commandes shell valides.
