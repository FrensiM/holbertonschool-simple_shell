#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
char *name;

/*String utilities functions */
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *string);
int _strcmp(char *s1, char *s2);
int _str_n_cmp(char *s1, char *s2, int n);

/* environment utilities */
char *_getenv(char *name);
int _printenv(void);

/* command path */
char *command_path(char *cmd);

/* main fun */
int execute(char *cmd_array[]);
int command_read(char *s, size_t __attribute__((unused)) characters);

#endif
