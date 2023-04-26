#include "shell.h"
/**
 * command_read - func that read commands
 * @s: comand
 * @characters: charact
 * Return: return value
 */
int command_read(char *s, size_t __attribute__((unused)) characters)
{
	char *token = NULL;
	char *path_array[100];
	int i = 0;

	if (_strcmp(s, "exit") == 0)
	{
		return (2);
	}
	if (_strcmp(s, "env") == 0)
	{
		return (_printenv());
	}
	path_array[0] = NULL;
	token = strtok(s, " ");
	if (token == NULL)
		return (0);
	while (token)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	path_array[i] = NULL;
	if (_strlen(path_array[0]) == 0)
	{
		free(path_array[0]);
		path_array[0] = NULL;
	}
	return (execute(path_array));
}
/**
 * execute - fun that execute comand
 * @cmd_array: array of comand
 * Return: return value 0
 */
int execute(char *cmd_array[])
{
	char *path = NULL;
	pid_t pid;
	int var;
	char *cmd = NULL;

	cmd = cmd_array[0];
	path = command_path(cmd);

	if (path == NULL)
	{
		write(2, _strcat(cmd, ": Not found\n"), _strlen(cmd) + 12);
		return (3);
		/*
		write(2, name, _strlen(name));
		write(2, ": ", 2);
		write(2, cmd, _strlen(cmd));
		write(2, ": not found\n", 12);
		return (3);
		*/
	}
	pid = fork();

	if (pid < 0)
	{
		perror("Error creating child\n");
		return (-1);
	}
	if (pid > 0)
	{
		wait(&var);
	}
	else
	{
		if (environ)
		{
			execve(path, cmd_array, environ);
			perror("Error");
			exit(2);
		}
		else
			execve(path, cmd_array, NULL);
	}
	free(path);
	return (0);
}
