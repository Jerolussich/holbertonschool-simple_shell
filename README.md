# C - Holberton Simple Shell
[![holberton](https://user-images.githubusercontent.com/113919186/207066528-0e8569ab-4132-4b02-8eb3-176e58a0dc7b.png)](https://www.holbertonschool.com/)
## Description
**hsh** *(Holberton SHell)* is an **sh-compatible** command language interpreter that shall **execute commands** read from a command line string, the standard input, or a specified file.
### Requirements
This is a group project made for Holberton, and it had the following requirements.
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic-std=gnu89`
- All files should end with a new line
- Code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- Shell should not have any memory leaks
- No more than 5 functions per file
- All header files should be include guarded
- Use system calls only when needed
## Usage
Hsh should work like this in interactive mode:

    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $
But also in non-interactive mode:

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_Is_2
    $
    $ cat test_Is_2
    /bin/ls
    /bin/ls
    $
    $ cat test_Is_2|/hsh
    hsh main.c shell.c test_Is_2
    hsh main.c shell.c test_ls_2
    $
## File Description
+ **aux_functions.c** - contains auxiliar functions:
    + *_strcat* - concatenate a string
    + *_strcmp* - compare two string
    + *_strcpy* - copy the string to a buffer
    + *_strdup* - duplicate a string
    + *free_grid* - frees a 2 dimensional string
- **functions.c** - contains 5 functions:
    + *get_env* - a function that gets all the environmental path
    + *attach_path* - add the corresponding path to the given command
    + *shell_exit* - exits the main shell
    + *fork_handler* - creates a child process and executes the command
    + *execute* - tests that the first argument is executable
- **print_env.c** - print environment
- **functions_token.c** - has 1 function:
    + *tokenize_buffer* - tokenizes all the arguments that gets previously getline
- **main.h** - this is the header file, here are all the Macros, Libraries and prototypes that we use in the shell
- **simple_shell.c** - contains the main function that runs the simple shell
## Flowchart
[![Flowchart ](https://app.code2flow.com/elWLcW.png "Flowchart ")](https://app.code2flow.com/elWLcW.png "Flowchart ")
### Authors
Written by [Dario Nalerio](https://github.com/dariomnalerio), [Jeronimo Lussich](https://github.com/Jerolussich) and [Vicente Debrun](https://github.com/vviceen)
