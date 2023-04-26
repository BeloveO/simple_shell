#include "main.h"

/**
 * copy_info - copies info to create
 *	a new env or alias
 * @nm: name of env or alias
 * @val: value of env or alias
 * Return: new env or alias->
 */
char *copy_info(char *nm, char *val)
{
	char *new;
	int len_nm, len_val, len;

	len_nm = _strlen(nm);
	len_val = _strlen(val);
	len = len_nm + len_val + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, nm);
	_strcat(new, "=");
	_strcat(new, val);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 * @nm: name of the environment variable
 * @val: value of the environment variable
 * @datash: data structure (environ)
 */
void set_env(char *nm, char *val, data_shell *datash)
{
	int i;
	char *var_env, *nm_env;

	for (i = 0; datash->_env1[i]; i++)
	{
		var_env = _strdup(datash->_env1[i]);
		nm_env = _strtok(var_env, "=");
		if (_strcmp(nm_env, nm) == 0)
		{
			free(datash->_env1[i]);
			datash->_env1[i] = copy_info(nm_env, val);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_env1 = _reallocdp(datash->_env1, i, sizeof(char *) * (i + 2));
	datash->_env1[i] = copy_info(nm, val);
	datash->_env1[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 *	with the name passed->
 * @datash: data relevant (env name and env value)
 * Return: 1 on success->
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 * @datash: data relevant (env name)
 * Return: 1 on success->
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *nm_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_env1[i]; i++)
	{
		var_env = _strdup(datash->_env1[i]);
		nm_env = _strtok(var_env, "=");
		if (_strcmp(nm_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_env1[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->_env1[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_env1[k]);
	free(datash->_env1);
	datash->_env1 = realloc_environ;
	return (1);
}
