#include "shell.h"
int _printenv()
{
	char *str = environ[0];
	int i = 0;
	
	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, str, _strlen(str));
		write(STDOUT_FILENO, "\n", 1);
		str = environ[i];
		i++;
	}
	return (0);
}

#include <string.h>  // for strcmp() and strlen()
#include <stdlib.h>  // for environ global variable
char* _getenv(char* name)
{
	int len = _strlen(name);
	for (int i = 0; environ[i] != NULL; i++)
	{
		if (_str_n_cmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return &(environ[i][len+1]);
		}
	}
	return (NULL);
}
