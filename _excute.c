#include "shell.h"

int _excute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _path(command[0]);

	if (!full_cmd)
	{
		printerr(argv[0], command[0], idx);
		freearr(command);
		return (127);
	}
	child = fork();

	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freearr(command), command = NULL;
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearr(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
