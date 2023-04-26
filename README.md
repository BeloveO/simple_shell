# 0x16. C - Simple Shell

## Background Context
> Write a simple UNIX command interpreter.

## Overview
> simple_shell is a sh-compatible command language interpreter that executes commands read from the standard input or from a file.

### Invocation
> Usage: **simple_shell** simple_shell is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
./simple_shell 
```