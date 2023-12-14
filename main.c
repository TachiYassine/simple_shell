#include "shell.h"

/**
 * main - Entry point for a my simple shell program.
 *
 * @ac: Number of arguments passed to the program.
 * @av: Array of pointers to strings containing the arguments.
 *
 * Return: Exit status of the program.
 */
int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, idx = 0;
	(void) ac;

	while (1)
	{
		line = read_from_user();
		if (line == NULL) /* end of file or ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;

		command = tokenizer(line);
		if (command == NULL)
			continue;

		if (is_builtin(command[0]))
			handle_builtin(command, argv, &status, idx);
		else
			status = _execute(command, argv, idx);
	}
}
