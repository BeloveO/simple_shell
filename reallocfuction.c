#include "shell.h"

/**
 * ffree - frees a string of strings
 * @pointer: string of strings
 */
void ffree(char **pointer)
{
	char **ptr = pointer;

	if (!pointer)
		return;
	while (*pointer)
		free(*pointer++);
	free(ptr);
}

/**
 * _memset - function def
 * @ptr: is a variable
 * @byte: is a variable
 * @n: is a variable
 * Return: char
 */
char *_memset(char *ptr, char byte, unsigned int n)
{
	unsigned int count;

	for (count = 0; count < n; count++)
		ptr[count] = byte;
	return (ptr);
}

/**
 * _realloc - function def
 * @pointer: pointer to previous malloc'ated block
 * @prevSize: byte size of previous block
 * @CurrSize: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *pointer, unsigned int prevSize, unsigned int CurrSize)
{
	char *ptr;

	if (!pointer)
		return (malloc(CurrSize));
	if (!CurrSize)
		return (free(pointer), NULL);
	if (CurrSize == prevSize)
		return (pointer);

	ptr = malloc(CurrSize);
	if (!ptr)
		return (NULL);

	prevSize = prevSize < CurrSize ? prevSize : CurrSize;
	while (prevSize--)
		ptr[prevSize] = ((char *)pointer)[prevSize];
	free(pointer);
	return (ptr);
}


