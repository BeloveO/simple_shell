#include "main.h"
/**
 * assign_line - assigns line var for get_line
 * @linep: buffer to store input str
 * @n: size of line
 * @buffer: str that is called to line
 * @a: size of buffer
*/
void assign_line(char **linep, size_t *n, char *buffer, size_t a)
{
	if (*linep == NULL)
	{
		if (a > BUFSIZE)
			*n = a;
		else
			*n = BUFSIZE;
		*linep = buffer;
	}
	else if (*n < a)
	{
		if (a > BUFSIZE)
			*n = a;
		else
			*n = BUFSIZE;
		*linep = buffer;
	}
	else
	{
		_strcpy(*linep, buffer);
		free(buffer);
	}
}

/**
 * get_line - read input from stream
 * @linep: buffer to store input
 * @n: size of linep
 * @stream: stream to be read
 * Return: number of bytes
*/
ssize_t get_line(char **linep, size_t *n, FILE *stream)
{
	char *buffer, t = 'z';
	static ssize_t in;
	ssize_t rv;
	int i;

	if (in == 0)
		fflush(stream);
	else
		return (-1);
	in = 0;
	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && in == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && in != 0)
		{
			in++;
			break;
		}
		if (in >= BUFSIZE)
			buffer = _realloc(buffer, in, in + 1);
		buffer[in] = t;
		in++;
	}
	buffer[in] = '\0';
	assign_line(linep, n, buffer, in);
	rv = in;
	if (i != 0)
		in = 0;
	return (rv);
}
