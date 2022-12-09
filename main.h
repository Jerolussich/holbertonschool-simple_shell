#ifndef main_h
#define main_h
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Global variables*/

extern char **environ;

/* Functions prototypes*/

int main();
char *get_env(char *name);
char *find_path(char *str, char *input);
char *attach_path(char *str, char **input);
char **tokenize_buffer(char *buffer);
void shell_exit(char **token_array, char *buffer);
int fork_error_handler(char **token_array, char *buffer);
int execute(char **token_array, char *buffer);
void print_env();

/* Auxiliar functions prototypes*/

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void free_grid(char **grid);

#endif
