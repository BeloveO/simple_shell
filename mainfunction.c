#include "shell.h"

/**
 * main - functiondef
 * @argCount: is a variable
 * @argVec: is a variable
 * Return: 0
 */
int main(int argCount, char **argVec)
{
	info_t info[] = { INITINFO };
	int fileVal = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fileVal)
			: "r" (fileVal));

	if (argCount == 2)
	{
		fileVal = open(argVec[1], O_RDONLY);
		if (fileVal == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputsfunc(argVec[0]);
				_eputsfunc(": 0: Can't open ");
				_eputsfunc(argVec[1]);
				_eputcharacter('\n');
				_eputcharacter(FLUSHBUF);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fileVal;
	}
	populateenvlist(info);
	readHistory(info);
	hsh(info, argVec);
	return (EXIT_SUCCESS);
}

