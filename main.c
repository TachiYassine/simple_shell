#include "shell.h"

/**
 * main - simple shell main function that run all other functions
 * @ac: count of arguments
 * @av: arguments
 * 
 * Return: 0 Always (success).
 */

int main(int ac, char **av)
{
	char *line = NULL, **command = NULL;
	int status = 0;
	(void) ac;

	while(1)
	{
		line = read_from_user();
		if (line == NULL) /* end of file or ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n" , 1);
			return (status);
		}

		command = tokenizer(line);
		if (command == NULL)
			continue;

		status = _execute(command, av);
	}
}
