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
int _execute(char **command, char **argv, int idx);
char *_getenv(char *variable);
char *_getpath(char *command);

void freearray2D(char **arr);
void print_error(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);

int is_builtin(char *command);
void handle_builtin(char **commad, char **argv, int *status, int idx);
void exit_shell(char **commad, int *status);
void print_env(char **command, int *status);

char *_Str_duplicate(const char *str);
int _str_compare(char *str1, char *str2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
