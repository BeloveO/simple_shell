#include "main.h"
/**
 * main - main fun def
 * @argc: is arg count
 * @argv: is arg vector
 * Return: int
 */
int main(int ac, char **argv)
{
	char *prompt = "simple_shell$ ";
	char *linep = NULL, *linep_cpy = NULL;
	size_t n = 0;
	ssize_t nchar;
	const char *delim = " \n";
	int ntokens = 0, i;
	char *token;
	(void)ac;
	
	while (1)
	{
		printf("%s", prompt);
		nchar = getline(&linep, &n, stdin);
		if (nchar == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}
		linep_cpy = malloc(sizeof(char) * nchar);
		if (linep_cpy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(linep_cpy, linep);
		token = strtok(linep, delim);
		while (token != NULL)
		{
			ntokens++;
			token = strtok(NULL, delim);
		}
		ntokens++;
		argv = malloc(sizeof(char *) * ntokens);
		token = strtok(linep_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execcmd(argv);
	}
	free(linep_cpy);
	free(linep);
	return (0);
}
