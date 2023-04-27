#include "shell.h"

/**
 * populateenvlist - function def
 * @varInfo: is a variable
 * Return: 0
 */
int populateenvlist(info_t *varInfo)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		addNodeEnd(&node, environ[i], 0);
	varInfo->env = node;
	return (0);
}

/**
 * _ourunsetenv - function def
 * @varInfo: is a variable
 * Return: 0
 */
int _ourunsetenv(info_t *varInfo)
{
	int count;

	if (varInfo->argc == 1)
	{
		_eputsfunc("Too few arguements.\n");
		return (1);
	}
	for (count = 1; count <= varInfo->argc; count++)
		_unsetenv(varInfo, varInfo->argv[count]);

	return (0);
}

