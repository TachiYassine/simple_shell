#ifndef SHELL_H
#define SHELL_H

#define DELIMITER " \t\n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

char *read_from_user(void);
char **tokenizer(char *line);
int _execute(char **command, char **argv);
void freearray2D(char **arr);


char *_Str_duplicate(const char *str);
int _str_compare(char *str1, char *str2);
int _strlen(char *s);
char * _strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
