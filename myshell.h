#ifndef __MYSHELL_H_
#define __MYSHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#define MAX_ARG  20
#define MAX_LINE 100

char *buffer;

void typePrompt();
int inputCommand(char **command, char **parameter);

#endif // __MYSHELL_H_
