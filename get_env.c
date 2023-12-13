#include "shell.h"

/**
 * _getenv - get data
 * @variable: command from user
 *
 * Return: (NULL)
 */

char *_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _Str_duplicate(environ[i]);
		key = strtok(tmp, "=");
		if (_str_compare(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _Str_duplicate(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
