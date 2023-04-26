#include "main.h"
/**
 * cmp_env - Compares environment variable names
 * @nenv: name of env variable
 * @nm: name passed
 * Return: 0 if env variable names are not equal
*/
int cmp_env(const char *nenv, const char *nm)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != nm[i])
		{
			return (0);
		}
	}
	return (i + 1);
}

/**
 * _getenv - get env variable
 * @nm: name of env variable
 * @_env1: env variable
 * Return: value of env variable if found
*/
char *_getenv(const char *nm, char **_env1)
{
	int i, j = 0;
	char *ptr_env;

	ptr_env = NULL;

	for (i = 0; _env1[i]; i++)
	{
		j = cmp_env(_env1[i], nm);
		if (j)
		{
			ptr_env = _env1[i];
			break;
		}
	}

	return (ptr_env + j);
}

/**
 * _env - print env variable
 * @datash: data relevant
 * Return: success(1)
*/
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_env1[i]; i++)
	{
		for (j = 0; datash->_env1[i][j]; j++)
			;
		write(STDOUT_FILENO, datash->_env1[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
