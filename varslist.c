#include "shell.h"

/**
 * replaceAlias - main function
 * @varInfo: info variable
 *
 * Return: 1
 */
int replaceAlias(info_t *varInfo)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = nodeStartWith(varInfo->alias, varInfo->argv[0], '=');
		if (!node)
			return (0);
		free(varInfo->argv[0]);
		p = _strchar(node->str, '=');
		if (!p)
			return (0);
		p = _strdupcase(p + 1);
		if (!p)
			return (0);
		varInfo->argv[0] = p;
	}
	return (1);
}



/**
 * checkChain - main entry
 * @varInfo: is a variable
 * @varBuffer: var buffer
 * @p: pointer
 * @i: is a variable
 * @len: length
 *
 * Return: nothing
 */
void checkChain(info_t *varInfo, char *varBuffer, size_t *p,
size_t i, size_t len)
{
	size_t sizeC = *p;

	if (varInfo->cmd_buf_type == ANDCMD)
	{
		if (varInfo->status)
		{
			varBuffer[i] = 0;
			sizeC = len;
		}
	}
	if (varInfo->cmd_buf_type == ORCMD)
	{
		if (!varInfo->status)
		{
			varBuffer[i] = 0;
			sizeC = len;
		}
	}

	*p = sizeC;
}

/**
 * isChain - function def
 * @varInfo: is a variable
 * @varBuffer: buffer var
 * @p: pointer
 *
 * Return: 1
 */
int isChain(info_t *varInfo, char *varBuffer, size_t *p)
{
	size_t sizeC = *p;

	if (varBuffer[sizeC] == '|' && varBuffer[sizeC + 1] == '|')
	{
		varBuffer[sizeC] = 0;
		sizeC++;
		varInfo->cmd_buf_type = ORCMD;
	}
	else if (varBuffer[sizeC] == '&' && varBuffer[sizeC + 1] == '&')
	{
		varBuffer[sizeC] = 0;
		sizeC++;
		varInfo->cmd_buf_type = ANDCMD;
	}
	else if (varBuffer[sizeC] == ';') /* found end of this command */
	{
		varBuffer[sizeC] = 0; /* replace semicolon with null */
		varInfo->cmd_buf_type = CHAINCMD;
	}
	else
		return (0);
	*p = sizeC;
	return (1);
}




