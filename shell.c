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

	token = strtok(s, " ");

	if (_strcmp(s, "exit") == 0)
		return (2);
	if (_strcmp(s, "env") == 0)
		return (_printenv());

	while (token != NULL)
	{
		path_array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	path_array[i] = NULL;

	return (execute(path_array));
}
/**
 * execute - fun that execute comand
 * @cmd_array: array of comand
 * Return: return value 0
 */
int execute(char *cmd_array[])
{
	char *path;
	pid_t pid;
	int var;
	char *cmd = NULL;

	cmd = cmd_array[0];
	path = command_path(cmd);

	if (path == NULL)
	{
		write(2, name, _strlen(name));
		write(2, ": ", 2);
		write(2, cmd, _strlen(cmd));
		write(2, ": not found\n", 12);
		return (3);
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
	else if (pid == 0)
	{
		if (environ)
		{
			execve(path, cmd_array, environ);
			perror("execve");
			exit(1);
		}
		else
			execve(path, cmd_array, NULL);
	}
	free(path);
	return (0);
}
