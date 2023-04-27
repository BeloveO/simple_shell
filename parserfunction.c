#include "shell.h"



/**
 * dup_chars - function def
 * @sourcestr: string
 * @begin: is a variable
 * @end: is ending variable
 * Return: char
 */
char *dup_chars(char *sourcestr, int begin, int end)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = begin; i < end; i++)
		if (sourcestr[i] != ':')
			buf[k++] = sourcestr[i];
	buf[k] = 0;
	return (buf);
}
/**
 * is_cmd - function def
 * @varInfo: is a variable
 * @source: is a variable
 * Return: 1
 */
int is_cmd(info_t *varInfo, char *source)
{
	struct stat cust;

	(void)varInfo;
	if (!source || stat(source, &cust))
		return (0);

	if (cust.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * find_path - function def
 * @varInfo: is a variable
 * @sourcestr: is a variable
 * @command: is a variable
 * Return: char
 */
char *find_path(info_t *varInfo, char *sourcestr, char *command)
{
	int i = 0, position = 0;
	char *source;

	if (!sourcestr)
		return (NULL);
	if ((_strlength(command) > 2) && startwith(command, "./"))
	{
		if (is_cmd(varInfo, command))
			return (command);
	}
	while (1)
	{
		if (!sourcestr[i] || sourcestr[i] == ':')
		{
			source = dup_chars(sourcestr, position, i);
			if (!*source)
				_strconcatenate(source, command);
			else
			{
				_strconcatenate(source, "/");
				_strconcatenate(source, command);
			}
			if (is_cmd(varInfo, source))
				return (source);
			if (!sourcestr[i])
				break;
			position = i;
		}
		i++;
	}
	return (NULL);
}






