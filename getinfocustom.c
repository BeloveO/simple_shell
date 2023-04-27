#include "shell.h"

/**
 * freeInfo - function def
 * @varInfo: is a variable
 * @value: is a variable
 */
void freeInfo(info_t *varInfo, int value)
{
	ffree(varInfo->argv);
	varInfo->argv = NULL;
	varInfo->path = NULL;
	if (value)
	{
		if (!varInfo->cmd_buf)
			free(varInfo->arg);
		if (varInfo->env)
			freeList(&(varInfo->env));
		if (varInfo->history)
			freeList(&(varInfo->history));
		if (varInfo->alias)
			freeList(&(varInfo->alias));
		ffree(varInfo->environ);
			varInfo->environ = NULL;
		bfree((void **)varInfo->cmd_buf);
		if (varInfo->readfd > 2)
			close(varInfo->readfd);
		_putchar(FLUSHBUF);
	}
}
/**
 * clearInfo - function def
 * @varInfo: is a variable
 */
void clearInfo(info_t *varInfo)
{
	varInfo->arg = NULL;
	varInfo->argv = NULL;
	varInfo->path = NULL;
	varInfo->argc = 0;
}

/**
 * setInfo - function def
 * @varInfo: is a variable
 * @argVec: argument vector
 */
void setInfo(info_t *varInfo, char **argVec)
{
	int i = 0;

	varInfo->fname = argVec[0];
	if (varInfo->arg)
	{
		varInfo->argv = stringtow(varInfo->arg, " \t");
		if (!varInfo->argv)
		{
			varInfo->argv = malloc(sizeof(char *) * 2);
			if (varInfo->argv)
			{
				varInfo->argv[0] = _strdupcase(varInfo->arg);
				varInfo->argv[1] = NULL;
			}
		}
		for (i = 0; varInfo->argv && varInfo->argv[i]; i++)
			;
		varInfo->argc = i;

		replaceAlias(varInfo);
		replaceVars(varInfo);
	}
}




