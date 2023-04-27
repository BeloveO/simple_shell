#include "shell.h"

/**
 * read_buf - function def
 * @varInfo: var info
 * @varBuffer: Buff var
 * @i: variable
 *
 * Return: sizet
 */
ssize_t read_buf(info_t *varInfo, char *varBuffer, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(varInfo->readfd, varBuffer, BUFSIZEREAD);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * input_buf - main entry
 * @varInfo: variable
 * @varBuffer: buffer variable
 * @length: variable lengthgth
 *
 * Return: ssize_t
 */
ssize_t input_buf(info_t *varInfo, char **varBuffer, size_t *length)
{
	ssize_t r = 0;
	size_t length_p = 0;

	if (!*length)
	{
		free(*varBuffer);
		*varBuffer = NULL;
		signal(SIGINT, signHandle);
#if LINEGETUSE
		r = getline(varBuffer, &length_p, stdin);
#else
		r = _getline(varInfo, varBuffer, &length_p);
#endif
		if (r > 0)
		{
			if ((*varBuffer)[r - 1] == '\n')
			{
				(*varBuffer)[r - 1] = '\0';
				r--;
			}
			varInfo->linecount_flag = 1;
			rmvComments(*varBuffer);
			buildHistoryListinfo_t(varInfo, *varBuffer, varInfo->histcount++);
			{
				*length = r;
				varInfo->cmd_buf = varBuffer;
			}
		}
	}
	return (r);
}

/**
 * getInput - function def
 * @varInfo: is a variable
 *
 * Return: sizet
 */
ssize_t getInput(info_t *varInfo)
{
	static char *varBuffer;
	static size_t i, j, length;
	ssize_t r = 0;
	char **buf_p = &(varInfo->arg), *p;

	_putchar(FLUSHBUF);
	r = input_buf(varInfo, &varBuffer, &length);
	if (r == -1)
		return (-1);
	if (length)
	{
		j = i;
		p = varBuffer + i;

		checkChain(varInfo, varBuffer, &j, i, length);
		while (j < length)
		{
			if (isChain(varInfo, varBuffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= length)
		{
			i = length = 0;
			varInfo->cmd_buf_type = NORMCMD;
		}

		*buf_p = p;
		return (_strlength(p));
	}

	*buf_p = varBuffer;
	return (r);
}




/**
 * signHandle - function def
 * @sig_num: sign var
 *
 * Return: nothing
 */
void signHandle(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(FLUSHBUF);
}

/**
 * _getline - function definition
 * @varInfo: is info variable
 * @pointer: pointer
 * @length: is a variable
 *
 * Return: int
 */
int _getline(info_t *varInfo, char **pointer, size_t *length)
{
	static char varBuffer[BUFSIZEREAD];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pointer;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(varInfo, varBuffer, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchar(varBuffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - varBuffer) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strnconcatenate(new_p, varBuffer + i, k - i);
	else
		_strncopy(new_p, varBuffer + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*pointer = p;
	return (s);
}




