#include "myshell.h"

int inputCommand(char **command, char **parameter) {
    buffer = (char *)malloc(50 * sizeof(char));
    if (buffer == NULL || fgets(buffer, MAX_LINE, stdin) == NULL) {
        exit(0);
    }

    if (*buffer == '\0') {
        return -1;
    }

    int count = 0;
    char *start, *end;
    start = end = buffer;
    while(1) {
        while(*start == ' ' || *start == '\t' || *start == '\n') {
            start++;
            end++;
        }

        while(*end != ' ' && *end != '\t' && *end != '\0' && *end != '\n') {
            end++;
        }

        if (count == 0) {
            *command   = start;
            *parameter = start;
            count += 2;
        } else if (count < MAX_ARG) {
            parameter[count-1] = start;
            count++;
        } else {
            break;
        }

        if (*end == '\0'|| *end == '\n') {
            *end = '\0';
            break;
        } else {
            *end = '\0';
            end++;
            start = end;
        }
    }

    parameter[count-1] = NULL;

    printf("command: %s\n", *command);
    for (int i = 0; i < count - 1; i++) {
        printf("parameter: [%s]\n", parameter[i]);
    }

    return count;
}
