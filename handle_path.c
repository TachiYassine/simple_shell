#include "shell.h"

/**
 * _getpath - Gets the path of a command.
 *
 * @command: Pointer to a string containing the command.
 *
 * Return: Pointer full path, NULL if the path not found or if error occurs
 */
char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if(command[i] == '/')
		{
			if (stat(command, &st) == 0) /* if path exist */
				return (_Str_duplicate(command));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir), _strcat(full_cmd, "/"), _strcpy(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL, dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
