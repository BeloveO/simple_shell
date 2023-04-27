#include "shell.h"



/**
 * print_error - function def
 * @varInfo: is a variable
 * @retVal: retuurn val
 * Return: nothing
 */
void print_error(info_t *varInfo, char *retVal)
{
	_eputsfunc(varInfo->fname);
	_eputsfunc(": ");
	printd(varInfo->line_count, STDERR_FILENO);
	_eputsfunc(": ");
	_eputsfunc(varInfo->argv[0]);
	_eputsfunc(": ");
	_eputsfunc(retVal);
}


/**
 * _erroratoi - function definition
 * @str: string variable
 * Return: int
 */
int _erroratoi(char *str)
{
	unsigned long int retVal = 0;
	int i = 0;

	if (*str == '+')
		str++;  /* TODO: why does this make main return 255? */
	for (i = 0;  str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			retVal *= 10;
			retVal += (str[i] - '0');
			if (retVal > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (retVal);
}



/**
 * convertnum - is a function
 * @Value: is a variable
 * @baseValue: value variable
 * @flagValue: value
 *
 * Return: string
 */
char *convertnum(long int Value, int baseValue, int flagValue)
{
	static char *lists;
	static char buffer[50];
	char sign = 0;
	char *pointer;
	unsigned long n = Value;

	if (!(flagValue & UNSIGNEDCVT) && Value < 0)
	{
		n = -Value;
		sign = '-';

	}
	lists = flagValue & LOWERCASECVT ? "0123456789abcdef" : "0123456789ABCDEF";
	pointer = &buffer[49];
	*pointer = '\0';

	do	{
		*--pointer = lists[n % baseValue];
		n /= baseValue;
	} while (n != 0);

	if (sign)
		*--pointer = sign;
	return (pointer);
}
/**
 * rmvComments - main function
 * @varBuffer: is a variable
 *
 * Return: 0
 */
void rmvComments(char *varBuffer)
{
	int count;

	for (count = 0; varBuffer[count] != '\0'; count++)
		if (varBuffer[count] == '#' && (!count || varBuffer[count - 1] == ' '))
		{
			varBuffer[count] = '\0';
			break;
		}
}
/**
 * printd - function def
 * @accept: accept variable
 * @fileVal: file value
 *
 * Return: int
 */
int printd(int accept, int fileVal)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fileVal == STDERR_FILENO)
		__putchar = _eputcharacter;
	if (accept < 0)
	{
		_abs_ = -accept;
		__putchar('-');
		count++;
	}
	else
		_abs_ = accept;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}




