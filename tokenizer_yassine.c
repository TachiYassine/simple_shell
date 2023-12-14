#include "shell.h"
/**
 * tokenizer - parsing a string into pieces
 * @line: input from user
 *
 * Return: array of string.
 */
char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);

	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		cpt++;
		token = strtok(NULL,DELIM);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, DELIM);
        while (token)
        {
                command[i] = _strdup(token);
                token = strtok(NULL,DELIM);
		i++;
        }
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
