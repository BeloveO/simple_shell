#include "main.h"
/**
 * _strtok - splits a string by some delimiter
 * @str: input string
 * @delim: delimiter
 * Return: string splited
 */
char *_strtok(char str[], const char *delim)
{
	static char *split, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		split = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = split;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *split; split++)
	{
		/*Breaking loop finding the next token*/
		if (split != str_start)
			if (*split && *(split - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*split == delim[i])
			{
				*split = '\0';
				if (split == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *split) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}
