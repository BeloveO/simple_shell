#include "shell.h"

/**
 * _ourcd - function def
 * @varInfo: is a variable
 * Return: int
 */
int _ourcd(info_t *varInfo)
{
	char *str, *value, buffer[1024];
	int chdir_ret;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!varInfo->argv[1])
	{
		value = _getEnvironment(varInfo, "HOME=");
		if (!value)
			chdir_ret =	chdir((value = _getEnvironment(varInfo, "PWD=")) ? value : "/");
		else
			chdir_ret = chdir(value);
	}
	else if (_strcompare(varInfo->argv[1], "-") == 0)
	{
		if (!_getEnvironment(varInfo, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getEnvironment(varInfo, "OLDPWD=")), _putchar('\n');
		chdir_ret = /** Line Check **/
		chdir((value = _getEnvironment(varInfo, "OLDPWD=")) ? value : "/");
	}
	else
		chdir_ret = chdir(varInfo->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(varInfo, "can't cd to ");
		_eputsfunc(varInfo->argv[1]), _eputcharacter('\n');
	}
	else
	{
		_setenv(varInfo, "OLDPWD", _getEnvironment(varInfo, "PWD="));
		_setenv(varInfo, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _ourexit - function def
 * @varInfo: is a variable
 * Return: int
 */
int _ourexit(info_t *varInfo)
{
	int exitcheck;

	if (varInfo->argv[1])
	{
		exitcheck = _erroratoi(varInfo->argv[1]);
		if (exitcheck == -1)
		{
			varInfo->status = 2;
			print_error(varInfo, "Illegal number: ");
			_eputsfunc(varInfo->argv[1]);
			_eputcharacter('\n');
			return (1);
		}
		varInfo->err_num = _erroratoi(varInfo->argv[1]);
		return (-2);
	}
	varInfo->err_num = -1;
	return (-2);
}



