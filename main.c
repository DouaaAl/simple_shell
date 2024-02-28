#include "shell.h"

/**
 * main: main function
 * @ac: first param
 * @argv: second param
 * Return: int returns integer
 */

int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0;
	(void) ac;

	while (1)
	{
		line = _get_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		command = splitter(line);

		if (!command)
			continue;

		status = _excute(command, argv);
		printf("%d\n", status);
	}
}
