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
	(void) av;

	while(1)
	{
		line = read_from_user();
		if (line == NULL) // end of file or ctrl + D
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n" , 1);
			return (status);
		}

		command = tokenizer(line);
		if (command == NULL)
			continue;

		for (i = 0; command[i]; i++)
		{
			printf("%s\n", command[i]);
			// we are not allow to use printf i will update it later
			free(command[i]);
			command[i] = NULL;
		}
		free(command), command = NULL;


	}
}
