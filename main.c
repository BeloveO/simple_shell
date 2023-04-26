#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "simple_shell$ ";
	char *linep = NULL, *linep_cpy = NULL, *token;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t nchar;
	int ntoken = 0, i;

	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		/* malloc to avoid the error memory being freed not allocated */
		/*char *str = malloc(sizeof(linep));*/
		/* gets the string user types in and passes it to linep */
		nchar = getline(&linep, &n, stdin);
		if (nchar == -1)
		{
			printf("Exiting shell.....\n");
			return (-1);
		}

		linep_cpy = malloc(sizeof(char) * nchar);
		if (linep_cpy == NULL)
		{
			perror("tsh: Memory allocation error");
			return (-1);
		}
		strcpy(linep_cpy, linep);

		token = strtok(linep, delim);

		while (token != NULL)
		{
			ntoken++;
			token = strtok(NULL, delim);
		}
		ntoken++;

		argv = malloc(sizeof(char *) * ntoken);

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

	free(argv);
	free(linep);
	free(linep_cpy);

	return (0);
}