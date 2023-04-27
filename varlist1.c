#include "shell.h"

/**
 * replaceString - main function
 * @prev: is a variable
 * @curr: is a string var
 *
 * Return: 1
 */
int replaceString(char **prev, char *curr)
{
	free(*prev);
	*prev = curr;
	return (1);
}

/**
 * replaceVars - tokensized ring replace
 * @varInfo: variable
 *
 * Return: 1
 */
int replaceVars(info_t *varInfo)
{
	int count = 0;
	list_t *node;

	for (count = 0; varInfo->argv[count]; count++)
	{
		if (varInfo->argv[count][0] != '$' || !varInfo->argv[count][1])
			continue;

		if (!_strcompare(varInfo->argv[count], "$?"))
		{
			replaceString(&(varInfo->argv[count]),
					_strdupcase(convertnum(varInfo->status, 10, 0)));
			continue;
		}
		if (!_strcompare(varInfo->argv[count], "$$"))
		{
			replaceString(&(varInfo->argv[count]),
					_strdupcase(convertnum(getpid(), 10, 0)));
			continue;
		}
		node = nodeStartWith(varInfo->env, &varInfo->argv[count][1], '=');
		if (node)
		{
			replaceString(&(varInfo->argv[count]),
					_strdupcase(_strchar(node->str, '=') + 1));
			continue;
		}
		replaceString(&varInfo->argv[count], _strdupcase(""));

	}
	return (0);
}


