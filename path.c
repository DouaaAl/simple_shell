#include "shell.h"

/**
 * _path - function
 * @command: function param
 * Return: returns char
 */

char *_path(char *command)
{
	char *path_env, *full_cmd, *dir;
	struct stat st;
	int i;

	path_env = _getenv("PATH");
	dir = strtok(path_env, ":");

	for (i = 0 ; command[i] ; i++)
	{
		if (command[i] == '/')
			{
				if (stat(command, &st) == 0)
						return (_strdup(command));	
			return (NULL);
		}
	}
	if (!path_env)
		return (NULL);
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
