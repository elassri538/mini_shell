#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "builtins.h"

#define MAX_CMD 1024

void afficher_prompt() {
    printf("mini-shell> ");
}

void lire_et_executer_commande() {
    char commande[MAX_CMD];
    if (!fgets(commande, MAX_CMD, stdin)) {
        return;
    }

    commande[strcspn(commande, "\n")] = '\0'; // Supprime le \n

    if (strlen(commande) == 0) return;

    if (strcmp(commande, "exit") == 0) {
        printf("Au revoir !\n");
        exit(0);
    } else if (est_commande_builtin(commande)) {
        executer_builtin(commande);
    } else {
        system(commande); // Exécute commande externe
    }
}
