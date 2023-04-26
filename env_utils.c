#include "shell.h"
/**
 * _printenv - print env
 * Return: value 0
 */
int _printenv(void)
{
	char *str = environ[0];
	int i = 0;

	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, str, _strlen(str));
		write(STDOUT_FILENO, "\n", 1);
		str = environ[i];
		++i;
	}
	return (0);
}
/**
 * *_getenv - geting env
 * @name: name
 * Return: NULL
 */
char *_getenv(char *name)
{
	int len = _strlen(name);
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_str_n_cmp(environ[i], name, len) == 0)
		{
			return (&environ[i][len]);
		}
	i++;
	}
	return (NULL);
}
