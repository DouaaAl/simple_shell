#include "shell.h"

int _excute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();

	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freearr(command);
			exit(99);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearr(command);
	}
	return (WEXITSTATUS(status));
}
