#include "shell.h"

/**
* get_path - a function to get the path.
* @env: parameter.
*
* Return: result or NULL.
*/

char *get_path(char **env)
{
	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
		}
		env++;
	}
	return (NULL);
}
