#include "main.h"

/**
 * exit_shell - exits the shell
 * @datash: data structure (status and args)
 * Return: success(0).
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;
	int is_digit, str_len, b_num;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		b_num = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || b_num)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}
