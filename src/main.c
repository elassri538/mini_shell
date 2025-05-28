#include <stdio.h>
#include "shell.h"

int main() {
    printf("Welcome to the mini shell! Tapez 'exit' pour quitter.\n");

    while (1) {
        afficher_prompt();
        lire_et_executer_commande();
    }

    return 0;
}
