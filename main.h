#ifndef main_h
#define main_h
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>

/* Global variables*/

extern char **environ;

/* Functions prototypes*/

int main(void);
char *get_env(char *name);
char *find_path(char *str, char *input);
char *attach_path(char *str, char **input);
char **tokenize_buffer(char *buffer);
void shell_exit(char **token_array, char *buffer, int status);
int fork_handler(char **token_array, char *buffer);
int execute(char **token_array, char *buffer, int count, int status);
void print_env(void);

/* Auxiliar functions prototypes*/

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void free_grid(char **grid);
char *_strstr(char *haystack, char *needle);

#endif
