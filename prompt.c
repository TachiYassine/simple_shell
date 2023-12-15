#include "shell.h"

/**
 * prompt - Function to display a prompt and execute commands
 * @av: Array of pointers to strings containing program arguments
 * @env: Array of pointers to strings containing environment variables
 *
 * Description:
 * This function displays a prompt (if STDIN is a terminal) and continuously
 * reads input from user. then executes the entered command using execve.
 * If the command does not exist, it prints an error message indicating so.
 * The function runs in an infinite loop until terminated externally.
 */

void prompt(char **av, char **env)
{
	char *string = NULL;
	int i, status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[] = {NULL, NULL}; /* char **argv */
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
			i++;
		}
		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror(av[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
}
