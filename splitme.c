#include "shell.h"

/**
* splitter - a function to split strings
* @buffer: the string to be operated.
* @del: the delimeter.
*
* Return: a pointer to the result.
*/

char **splitter(char *buffer, char *del)
{
	char *token, **tokens;

	int i = 0;

	tokens = malloc(sizeof(char *) * MAX_ARGS);
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, del);
	while (token && i < MAX_ARGS - 1)
	{
		tokens[i++] = token;
		token = strtok(NULL, del);
	}
	tokens[i] = NULL;
	return (tokens);
}
