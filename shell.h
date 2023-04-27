#ifndef OURSHELL
#define OURSHELL

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



#define LINEGETUSE 0
#define STRTKUSE 0

#define BUFSIZEREAD 1024
#define BUFSIZEWRITE 1024
#define FLUSHBUF -1


#define LOWERCASECVT	1
#define UNSIGNEDCVT	2

#define NORMCMD	0
#define ORCMD		1
#define ANDCMD		2
#define CHAINCMD	3

#define FILEHIST	".simple_shell_history"
#define MAXHIST	4096

extern char **environ;

/**
 * struct liststr - custom linked list
 * @num: variable for number list
 * @str: variable for string value
 * @next: pointing to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 * struct passinfo - strcture form,
 * @arg: variable for argument
 * @argv: argument vector
 * @path: string for current command
 * @argc: argument count
 * @line_count: line count
 * @err_num: error number value
 * @linecount_flag: flag count of lines
 * @fname: file name of the program
 * @env: envorin value of custom
 * @environ: envirno value
 * @history: history value
 * @alias: alias node
 * @env_changed: environ value changed
 * @status: status of exit
 * @cmd_buf: buffor
 * @cmd_buf_type: buff type
 * @readfd: read value
 * @histcount: history count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;


/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;




#define INITINFO \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);






int _strlength(char *);
int _strcompare(char *, char *);
char *startwith(const char *, const char *);
char *_strconcatenate(char *, char *);

int _eputcharacter(char);
void _eputsfunc(char *);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);


char *_strncopy(char *, char *, int);
char *_strnconcatenate(char *, char *, int);
char *_strchar(char *, char);


int builtinfind(info_t *);

int hsh(info_t *, char **);

void cmdfork(info_t *);
void cmdfind(info_t *);

char *_strdupcase(const char *);
char *_strcopy(char *, char *);

int _putchar(char);
void _puts(char *);

char **stringtow(char *, char *);
char **stringtowsec(char *, char);


char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


int bfree(void **);


int interactive(info_t *);
int is_delimitor(char, char *);
int _isalphabet(int);
int _atoi(char *);


int _erroratoi(char *);
void print_error(info_t *, char *);
int printd(int, int);
char *convertnum(long int, int, int);
void rmvComments(char *);


int _ourexit(info_t *);
int _ourcd(info_t *);
int _ourhelp(info_t *);

int _ourhistory(info_t *);
int _ouralias(info_t *);


char *gethisfile(info_t *info);
int readHistory(info_t *info);
int writeHistory(info_t *info);
int renumHistory(info_t *info);
int buildHistoryListinfo_t(info_t *info, char *buf, int linecount);

ssize_t getInput(info_t *);
void signHandle(int);
int _getline(info_t *, char **, size_t *);

void clearInfo(info_t *);
void setInfo(info_t *, char **);
void freeInfo(info_t *, int);

char *_getEnvironment(info_t *, const char *);
int _ourenv(info_t *);
int _oursetenv(info_t *);
int _ourunsetenv(info_t *);
int populateenvlist(info_t *);


char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);


void checkChain(info_t *, char *, size_t *, size_t, size_t);
int isChain(info_t *, char *, size_t *);
int replaceVars(info_t *);
int replaceAlias(info_t *);
int replaceString(char **, char *);

list_t *add_node(list_t **, const char *, int);
size_t printListString(const list_t *);
list_t *addNodeEnd(list_t **, const char *, int);
void freeList(list_t **);
int deleteNodeAtIndex(list_t **, unsigned int);


size_t listLength(const list_t *);
size_t printList(const list_t *);
char **listToStr(list_t *);
ssize_t getNodeAtIndex(list_t *, list_t *);
list_t *nodeStartWith(list_t *, char *, char);

int loopHsHValues(char **);

#endif
