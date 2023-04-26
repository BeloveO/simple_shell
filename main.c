#include "main.h"
/**
 * free_data - free data structure
 * @datash: data structure
*/
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_env1[i]; i++)
		free(datash->_env1);
	free(datash->_env1);
	free(datash->pid);
}

/**
 * set_data - init data structure
 * @datash: data structure
 * @argv: argument vector
*/
void set_data(data_shell *datash, char **argv)
{
	unsigned int i;

	datash->argv = argv;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; env[i]; i++)
		;
	datash->_env1 = malloc(sizeof(char *) * (i + 1));

	for (i = 0; env[i]; i++)
		datash->_env1[i] = _strdup(env[i]);

	datash->_env1[i] = NULL;
	datash->pid = _itoa(getpid());
}

/**
 * main - main fun def
 * @argc: is arg count
 * @argv: is arg vector
 * Return: success(0)
 */
int main(int argc, char **argv)
{
	data_shell datash;
	(void) argc;

	signal(SIGINT, sigint);
	set_data(&datash, argv);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
