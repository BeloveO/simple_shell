#include "main.h"
/**
 * execcmd - main function
 * @argv: is argument vector
 * Return: Nothing
 */
void execcmd(char **argv)
{
	char *cmd = NULL, *real_cmd = NULL;

	if (argv != NULL)
	{
		cmd = argv[0];

		real_cmd = getpath(cmd);

		if (execve(real_cmd, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
