#include "shell.h"

/**
 * bfree - function def
 * @pointer: ptr for free add
 *
 * Return: 1
 */
int bfree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}

