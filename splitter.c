#include "shell.h"

/**
 * splitter - tokenizes command line
 * @line: the command line
 * Return: returns 2d array
 */

char **splitter(char *line)
{
	char *token = NULL, delim[] = " \t\n";
	char *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, delim);

	while (token)
	{
		cpt++;
		token = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (cpt + 1));

	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, delim);

	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;

	return (command);
}
