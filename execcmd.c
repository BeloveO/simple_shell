#include "main.h"
/**
 * execcmd - main function
 * @argv: is argument vector
 * Return: Nothing
 */
void execcmd(char **argv)
{
	char *cmd = NULL, *real_cmd = NULL;
	int status;
	pid_t pid;

	if (argv != NULL)
	{
		cmd = argv[0];

		real_cmd = getpath(cmd);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		/*Child process: execute the command */
		execvp(argv[0], argv);
		perror("execvp");
		exit(1);
	}
	else
	{
		/*Parent process: wait for the child to finish */
		waitpid(pid, &status, 0);
	}
}
