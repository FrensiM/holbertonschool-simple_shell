#include "shell.h"

int command_read(char *s, size_t characters)
{
	char *token = NULL;
	char *path_array[100];
	int i = 0;
	token = strtok(s, " ");

	if (str_cmp(s, "exit"))
		return (2);
	if (str_cmp(s,"env"))
		return (_printenv());

	while (token != NULL)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, " ")
	}
	path_array[i] = NULL;
	return execute (path_array);
}
