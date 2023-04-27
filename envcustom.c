#include "shell.h"
/**
 * _oursetenv - function def
 * @varInfo: is a variable name
 *  Return: 0
 */
int _oursetenv(info_t *varInfo)
{
	if (varInfo->argc != 3)
	{
		_eputsfunc("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(varInfo, varInfo->argv[1], varInfo->argv[2]))
		return (0);
	return (1);
}


/**
 * _getEnvironment - function def
 * @varInfo: is a variable
 * @varName: is a variable
 *
 * Return: char
 */
char *_getEnvironment(info_t *varInfo, const char *varName)
{
	list_t *node = varInfo->env;
	char *pointer;

	while (node)
	{
		pointer = startwith(node->str, varName);
		if (pointer && *pointer)
			return (pointer);
		node = node->next;
	}
	return (NULL);
}

/**
 * _ourenv - function def
 * @varInfo: is a variable
 * Return: int
 */
int _ourenv(info_t *varInfo)
{
	printListString(varInfo->env);
	return (0);
}

