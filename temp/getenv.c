#include "main.h"

/**
 * _getenv - function to get the environment of a variable
 * @varname: name of variable
 * Return: environment value
*/
char *_getenv(const char *varname)
{
	char *value = NULL, **env;
	size_t varname_len = strlen(varname);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(varname, *env, varname_len) == 0 && (*env)[varname_len] == '=')
		{
			value = &(*env)[varname_len + 1];  /* Pointer to the value string */
			break;
		}
	}

	if (value == NULL)
	{
		fprintf(stderr, "%s environment variable not set\n", varname);
	}

	return (value);
}
