#include "shell.h"

/**
* main - the main function for my simple shell.
*
* Return: Always 0 (Success).
*/

int main(void)
{
	size_t bufsize = 0;
	char **args, *cmd, *buff = NULL;

	pid_t pid;
	int status, count, exit_status;

	while (1)
	{
		write(1, "$ ", 2);
		count = getline(&buff, &bufsize, stdin);
		_check(count);
		args = splitter(buff, " \t\n");
		if (strcmp(args[0], "exit") == 0)
		{
			if (args[1] != NULL)
			{
				exit_status = _atoi(args[1]);
				exit(exit_status);
			}
			else
				exit(0);
		}
		pid = fork();
		if (pid == 0)
		{
			cmd = get_command(args[0], environ);
			if (cmd)
				execve(cmd, args, environ);
			else
				write(1, "Command not found\n", 18);
			exit(0);
		}
		else
			wait(&status);
	}
	free(buff);
	free(args);
	return (0);
}
