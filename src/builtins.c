#include <stdio.h>
#include <string.h>
#include <unistd.h>

int est_commande_builtin(const char *cmd) {
    return strcmp(cmd, "pwd") == 0 ||
           strncmp(cmd, "cd ", 3) == 0 ||
           strcmp(cmd, "clear") == 0;
}

void executer_builtin(const char *cmd) {
    if (strcmp(cmd, "pwd") == 0) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
    } else if (strncmp(cmd, "cd ", 3) == 0) {
        const char *path = cmd + 3;
        if (chdir(path) != 0) {
            perror("cd");
        }
    } else if (strcmp(cmd, "clear") == 0) {
        printf("\033[H\033[J"); // Nettoie l'écran
    } else {
        printf("Commande inconnue : %s\n", cmd);
    }
}
