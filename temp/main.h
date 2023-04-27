#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;  /* pointer to the environment array */

void execcmd(char **argv);
char *getpath(char *cmd);
char* _getenv(const char* varname);

/* Function Calls */
char *_strdup(const char* str);
int _strncmp(const char* s1, const char* s2, size_t n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_memcpy(char *dest, const char *src, unsigned int n);

#endif
