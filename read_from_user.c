#include "shell.h"

/**
 * read_from_user - Reads a string input from the user.
 *
 * Return: Pointer to the string read from the user.
 *         NULL if an error occurs or if the input is empty.
 */
char *read_from_user(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
