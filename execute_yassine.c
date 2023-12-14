#include "shell.h"

/**
 * _execute - execute command from user
 * @command: from user
 * @argv: arguments
 *
 * Return: 0 in success
 */

int _execute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freearray2D(command);
			exit(100);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray2D(command);
	}

	return (WEXITSTATUS(status));
}
