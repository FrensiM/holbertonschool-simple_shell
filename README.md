# Simple Shell

A very basic Unix command line Interpreter written in C programming language as part of the Holberton-School curriculum.

## Description

This version of the Simple Shell can do the following:

- Displays a promt ($ ) and waits for the user to input the command :

```bash
./hsh
$ ls
AUTHORS  hsh  main.c  main.h  other_utilities.c  README.md  string_utilities.c
$ 
```
- The user is promted again after each command has been executed
- If the executable program is not found, prints an error message and exits the program

```bash
$ hi
./hsh: 1: hi: not found
root@bab1fb24f903:~/holbertonschool-simple_shell#
```
The program works in both interactive and non-interactive mode:
- Interactive Mode
```bash
./hsh 
$ ls
AUTHORS  hsh  main.c  main.h  man_1_simple_shell  other_utilities.c  README.md	string_utilities.c
$
```
- Non-Interactive Mode
```bash
echo "/bin/ls" | ./hsh
AUTHORS  hsh  main.c  main.h  man_1_simple_shell  other_utilities.c  README.md	string_utilities.c
```

## Compiling
The program is compiled using the following command:

**gcc -Wall -Werror -Wextra -pedantic -std=gnu89 .c -o hsh**
## Authors

- Frensi Meta
- Sindi Hamataj
