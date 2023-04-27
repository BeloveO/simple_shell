#include "main.h"
/**
 * main - main fun def
 * @argc: is arg count
 * @argv: is arg vector
 * Return: int
 */
int main(int argc, char **argv)
{
	char *prompt = "simple_shell$ ", *linep = NULL, *linep_cpy = NULL, *token;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t nchar;
	int ntoken = 0, i;

	(void)argc;
	while (1)
	{
		printf("%s", prompt);
		nchar = getline(&linep, &n, stdin);
		if (nchar == -1)
			return (-1);
		linep_cpy = malloc(sizeof(char) * nchar);
		if (linep_cpy == NULL)
		{
			return (-1);
		} strcpy(linep_cpy, linep);
		token = _strtok(linep, delim);
		while (token != NULL)
		{
			ntoken++;
			token = _strtok(NULL, delim);
		} ntoken++;
		argv = malloc(sizeof(char *) * ntoken);
		token = _strtok(linep_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = _strtok(NULL, delim);
		} argv[i] = NULL;
		if (_strcmp(argv[0], "exit") == 0)
		{
			break;
		} execcmd(argv);
	}
	free(linep_cpy);
	free(linep);
	return (0);
}
