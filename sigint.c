#include "main.h"
/**
 * sigint - Handle CTRL + c call
 * @sig: signal handler
*/

void sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
