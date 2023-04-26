#include "shell.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument values
 * Return: Always 0 (Success)
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL;
	size_t buff_size = 0;
	ssize_t characters = 0;
	int read_value;
	name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		characters = getline(&line, &buff_size, stdin);

		if (characters == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}

		if (line[characters - 1] == '\n')
			line[characters - 1] = '\0';
		if (*line == '\0')
			continue;
		read_value = command_read(line, characters);
		if (read_value == 2)
			break;
		else if (read_value == 1)
			return (2);
	}
	free(line);
	line = NULL;
	return (0);
}
