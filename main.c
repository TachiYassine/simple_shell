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
	int status = 0;
	char *line = NULL;
	char **command = NULL;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL) /* rech end of file */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}


		command = tokenizer(line);
		if (!command)
			continue;
		
		status = _execute(command, argv);
	}
}
