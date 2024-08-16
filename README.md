# Simple shell
This is a simple UNIX interpreter project written in C
## Compilation

To compile the shell, use the following command:

bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

USAGE 

Interactive mode 
$ ./hsh
($) /bin/ls
($) exit
$

Non-Interactive mode
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
$


Features
Display a prompt and wait for the user to type a command.
Execute simple commands (no arguments, no advanced features).
Handle errors like "command not found."
Handle the end of file (Ctrl+D).

Authors
Joshua Bamidele


