#include "shell.h"

/**
* get_command - a getcommand function.
* @command: the command to be get.
* @env: parameter.
*
* Return: a pointer to a string of the full command.
*/

char *get_command(char *command, char **env)
{
	char *enpath, *token, *full_command;

	struct stat st;

	enpath = get_path(env);
	if (!enpath)
	{
		return (NULL);
	}
	token = strtok(enpath, ":");
	while (token)
	{
		full_command = malloc(strlen(token) + strlen(command) + 2);
		if (!full_command)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(full_command, token);
		strcat(full_command, "/");
		strcat(full_command, command);

		if (stat(full_command, &st) == 0)
		{
			return (full_command);
		}
		free(full_command);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
