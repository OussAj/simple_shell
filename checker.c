#include "shell.h"

/**
* _check - a function to check.
* @count: parameter.
*
* Return: always 0.
*/

int _check(int count)
{
	if (count == -1)
	{
		write(1, "\n", 1);
		exit(1);
	}
	return (0);
}
