#include "shell.h"

void freearr(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0 ; arr[i] ; i++)
		free(arr[i]), arr[i] = NULL;
	free(arr), arr = NULL;
}
