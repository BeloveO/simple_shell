#include "shell.h"

/**
 * cmdfork - function def
 * @varInfo: the parameter & return info struct
 *
 * Return: nothing
 */
void cmdfork(info_t *varInfo)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(varInfo->path, varInfo->argv, get_environ(varInfo)) == -1)
		{
			freeInfo(varInfo, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(varInfo->status));
		if (WIFEXITED(varInfo->status))
		{
			varInfo->status = WEXITSTATUS(varInfo->status);
			if (varInfo->status == 126)
				print_error(varInfo, "Permission denied\n");
		}
	}
}

/**
 * builtinfind - main entry
 * @varInfo: is a variable
 * Return: int
 */
int builtinfind(info_t *varInfo)
{
	int i, retVal = -1;
	builtin_table builtintbl[] = {
		{"exit", _ourexit},
		{"env", _ourenv},
		{"help", _ourhelp},
		{"history", _ourhistory},
		{"setenv", _oursetenv},
		{"unsetenv", _ourunsetenv},
		{"cd", _ourcd},
		{"alias", _ouralias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcompare(varInfo->argv[0], builtintbl[i].type) == 0)
		{
			varInfo->line_count++;
			retVal = builtintbl[i].func(varInfo);
			break;
		}
	return (retVal);
}
/**
 * hsh - main entry
 * @varInfo: is a variable
 * @argVec: argument vec
 *
 * Return: 0
 */
int hsh(info_t *varInfo, char **argVec)
{
	ssize_t r = 0;
	int retVal = 0;

	while (r != -1 && retVal != -2)
	{
		clearInfo(varInfo);
		if (interactive(varInfo))
			_puts("$ ");
		_eputcharacter(FLUSHBUF);
		r = getInput(varInfo);
		if (r != -1)
		{
			setInfo(varInfo, argVec);
			retVal = builtinfind(varInfo);
			if (retVal == -1)
				cmdfind(varInfo);
		}
		else if (interactive(varInfo))
			_putchar('\n');
		freeInfo(varInfo, 0);
	}
	writeHistory(varInfo);
	freeInfo(varInfo, 1);
	if (!interactive(varInfo) && varInfo->status)
		exit(varInfo->status);
	if (retVal == -2)
	{
		if (varInfo->err_num == -1)
			exit(varInfo->status);
		exit(varInfo->err_num);
	}
	return (retVal);
}



/**
 * cmdfind - function def
 * @varInfo: info variable
 *
 * Return: void
 */
void cmdfind(info_t *varInfo)
{
	char *dest = NULL;
	int i, k;

	varInfo->path = varInfo->argv[0];
	if (varInfo->linecount_flag == 1)
	{
		varInfo->line_count++;
		varInfo->linecount_flag = 0;
	}
	for (i = 0, k = 0; varInfo->arg[i]; i++)
		if (!is_delimitor(varInfo->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	dest = /** line check **/
	find_path(varInfo, _getEnvironment(varInfo, "PATH="), varInfo->argv[0]);
	if (dest)
	{
		varInfo->path = dest;
		cmdfork(varInfo);
	}
	else
	{
		if ((interactive(varInfo) || _getEnvironment(varInfo, "PATH=")
					|| varInfo->argv[0][0] == '/') && is_cmd(varInfo, varInfo->argv[0]))
			cmdfork(varInfo);
		else if (*(varInfo->arg) != '\n')
		{
			varInfo->status = 127;
			print_error(varInfo, "not found\n");
		}
	}
}





