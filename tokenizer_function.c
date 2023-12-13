#include "shell.h"
/**
 * tokenizer - parsing a string into pieces
 * @line: input from user
 *
 * Return: array of string.
 */
char **tokenizer(char *line)
{
	char *token = NULL, *tmp_line = NULL, **command = NULL;
	int cpt_str = 0, i = 0;

	if (line == NULL)
		return (NULL);
	tmp_line = _Str_duplicate(line), token = strtok(tmp_line, DELIMITER);
	if (token == NULL)
	{
		free(line), line = NULL, free(tmp_line), tmp_line = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt_str++, token = strtok(NULL, DELIMITER);
	}
	free(tmp_line), tmp_line = NULL;
	command = malloc(sizeof(char *) * (cpt_str + 1));
	if (command == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIMITER);
	while (token)
	{
		command[i] = _Str_duplicate(token);
		token = strtok(NULL, DELIMITER), i++;
	}
	free(line), line = NULL, command[i] = NULL;
	return (command);
}
