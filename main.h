#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define DELIM " \t\r\n\a"

extern char **env;

void execcmd(char **argv);
char *getpath(char *cmd);
int _strcmp(char *s1, char *s2);

/**
 * struct data - structure that contains all the relevant data on runtime
 * @input:  command line input
 * @pid: process ID of th shell
 * @args: tokens of command line
 * @argv: argument vector
 * @_env1: environment variable
 * @status: last status of shell
 * @counter: lines count
*/
typedef struct data
{
	char *input;
	char *pid;
	char **args;
	char **argv;
	char **_env1;
	int status;
	int counter;
} data_shell;

/**
 * struct sep_list_s - single linked list to store separators
 * @separator: ; | &
 * @next: next node
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list to store command lines
 * @line: command line
 * @next: next node
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list to store variables
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* Lists Functions */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* String Functions */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
unsigned int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _isdigit(int c);
char *_strdup(const char *s1);
void rev_string(char *s);
char *_strtok(char str[], const char *delim);

/* Environment variables */
int _env(data_shell *datash);
char *_getenv(const char *nm, char **_env1);
int cmp_env(const char *nenv, const char *nm);
char *copy_info(char *nm, char *val);
void set_env(char *nm, char *val, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* Static Libraries */
int get_len(int n);
char *_itoa(int n);
int _atoi(char *s);

/* Signal Handler */
void sigint(int sig);

/* Memory Functions*/
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t old_len, size_t new_len);

/* get_line.c */
void assign_line(char **linep, size_t *n, char *buffer, size_t a);
ssize_t get_line(char **linep, size_t *n, FILE *stream);

/* Exit Shell */
int exit_shell(data_shell *datash);


#endif
