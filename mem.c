#include "main.h"
/**
 * *_memcpy - function that copies memory area
 * @dest: new copy destination
 * @src: source of copy
 * @n: number of elements to be copied
 * Return: new copied file (dest)
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _realloc - reallocate a memory block
 * @ptr: pointer to memory previously allocated
 * @old_len: bytes size of allocated memory for ptr
 * @new_len: new bytes size of new memory block
 * Return: ptr
*/
void *_realloc(void *ptr, size_t old_len, size_t new_len)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_len));
	if (new_len == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_len == old_len)
	{
		return (ptr);
	}
	newptr = malloc(new_len);
	if (newptr == NULL)
		return (NULL);
	if (new_len < old_len)
		_memcpy(newptr, ptr, new_len);
	else
		_memcpy(newptr, ptr, old_len);
	free(ptr);
	return (newptr);
}
