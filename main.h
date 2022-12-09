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

int main(int ac, char **av);
char *get_env(char *name);
char *find_path(char *str, char *input);
char *attach_path(char *str, char **input);
char **tokenize_buffer(char *buffer);
void shell_exit(char **token_array, char *buffer);
int fork_error_handler(char **token_array, char *buffer);
int execute(char **token_array, char *buffer);

/* Auxiliar functions prototypes*/

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void free_grid(char **grid);

/* Printf function protoypes */

int _printf(const char *format, ...);
int _putchar(char c);
int get_printf_func(va_list args, char spec);
int print_c(va_list args);
int print_p(va_list args);
int print_s(va_list args);
int print_num(va_list args);
void _print(long int n);

/**
 * struct strprt - Argument type and string to print
 *
 * @specifier: Type of argument
 * @f: Function associated
 */
typedef struct strprt
{
	char *specifier;
	int (*f)(va_list args);
} strprt_t;

#endif
