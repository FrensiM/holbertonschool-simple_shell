#include "shell.h"
/**
 * _printenv - print env
 * Return: value 0
 */
int _printenv(void)
{
	char **str;

	env = environ;

	while (*env)
	{
		write(1, *env, sizeof(char)* _strlen(*env));
		write(1, "\n", 1);
		++env;
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
