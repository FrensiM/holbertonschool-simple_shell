#include "shell.h"
/**
 * command_path - func that finds the path from environ
 * @cmd: comand
 * Return: full path
 */
char *command_path(char *cmd)
{
	char *path = _strdup(_getenv("PATH"));
	char *token = strtok(path, ":");
	char *path_array[100];
	char *new_path = NULL;
	struct stat buf;
	int i = 0;

	new_path = malloc(sizeof(char) * 100);
	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (_strdup(cmd));
	while (token != NULL)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	path_array[i] = NULL;

	for (i = 0; path_array[i]; i++)
	{
		_strcpy(new_path, path_array[i]);
		_strcat(new_path, "/");
		_strcat(new_path, cmd);
		_strcat(new_path, "\0");
		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);
	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));
	return (NULL);
}
