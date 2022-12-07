#ifndef main_h
#define main_h
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * struct list - structure for use in function selection
 * @cs: string
 * @f: pointer to function
 */
typedef struct list
{
	char *cs;
	int (*f)(va_list args);
} list_t;

int _putchar(char c);

int _printf(const char *format, ...);

int help(va_list args, char c);

int printcharacter(va_list args);

int printstring(va_list args);

int printporcentage(va_list args);

int printnumber(va_list args);

int printnumberunsig(unsigned int n);

#endif
