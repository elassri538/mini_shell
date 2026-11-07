# Mini Shell en C

Petit interpréteur de commandes réalisé en C pour pratiquer les entrées standard, les commandes internes et le lancement de commandes externes sous Linux.

## Fonctionnement

- Lit une ligne à la fois avec `fgets` (limite actuelle : 1 023 caractères).
- Exécute en interne `pwd`, `cd <répertoire>`, `clear` et `exit`.
- Transmet les autres lignes à `system()` : la syntaxe et l'exécution de ces commandes dépendent donc du shell système.

## Compiler et lancer

Prérequis : Linux ou environnement POSIX, GCC et Make.

```bash
make
./mini_shell
```

Exemple :

```text
mini-shell> pwd
/home/utilisateur/mini_shell
mini-shell> cd src
mini-shell> pwd
/home/utilisateur/mini_shell/src
mini-shell> exit
Au revoir !
```

Pour supprimer les fichiers générés : `make clean`.

## Organisation

| Chemin | Rôle |
| --- | --- |
| `src/main.c` | Boucle et message d'accueil |
| `src/shell.c` | Lecture et sélection des commandes |
| `src/builtins.c` | Implémentation des commandes internes |
| `include/` | Déclarations |
| `Makefile` | Compilation |

## Limites actuelles

Ce projet est une démonstration pédagogique, pas un shell complet. Il ne gère pas lui-même les processus, pipelines, redirections, signaux ni historique ; les commandes externes sont confiées à `system()`. La fin de l'entrée standard n'interrompt pas encore la boucle principale. Les arguments de `cd` sont interprétés comme un seul chemin.
