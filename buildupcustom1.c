#include "shell.h"
/**
 * _ourhelp - function def
 * @varInfo: is a variable
 * Return: 0
 */
int _ourhelp(info_t *varInfo)
{
	char **list;

	list = varInfo->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*list);

	return (0);

}
