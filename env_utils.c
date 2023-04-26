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
		write(1, str, _strlen(str));
		write(1, "\n", 1);
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

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_str_n_cmp(environ[i], name, len) == 0)
		{
			return (&environ[i][len]);
		}
	}
	return (NULL);
}
