#include "myshell.h"

void procc(void) {
    char *command = NULL;
    char **parameters = NULL;
    parameters = malloc(sizeof(char *) * (MAX_ARG + 2));
    if (parameters == NULL) { exit(0); }

    int childPid;
    int status;

    while(1) {
        typePrompt();

        if (inputCommand(&command, parameters) == -1) {
            continue;
        }

        if ((childPid = fork()) != 0) {
            waitpid(childPid, &status, 0);
        } else {
             execvp(command,parameters);
        }
    }
}

int main(void) {
    procc();

    return 0;
}
