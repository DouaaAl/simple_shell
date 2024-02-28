#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/*
 * shell functions
 */

char *_get_line(void);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **splitter(char *line);
void freearr(char **arr);
int _excute(char **command, char **argv);

/*
 * shell libraries
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#endif
