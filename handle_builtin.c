#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in command.
 *
 * @command: Pointer to a string containing the command.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	char *builtins[] = {"exit", "env", "cd", "setenv", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_str_compare(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - Handles execution of built-in commands.
 *
 * @command: Array of pointers to strings containing the command.
 * @argv: Array of pointers to strings containing arguments.
 * @status: Pointer to the status of the shell.
 * @idx: Index value.
 *
 * This function executes built-in commands based on the given command name.
 */
void handle_builtin(char **command, char **argv, int *status, int idx)
{
	(void) argv;
	(void) idx;

	if (_str_compare(command[0], "exit") == 0)
		exit_shell(command, status);
	else if (_str_compare(command[0], "env") == 0)
		print_env(command, status);
}

/**
 * exit_shell - Handles the exit command for shell termination.
 *
 * @command: Array of pointers to strings containing the command.
 * @status: Pointer to the status of the shell.
 *
 * This function releases memory allocated for the command and exits the shell
 * using the specified status.
 */
void exit_shell(char **command, int *status)
{
	freearray2D(command);
	exit(*status);
}

/**
 * print_env - Prints the environment variables.
 *
 * @command: Array of pointers to strings containing the command.
 * @status: Pointer to the status of the shell.
 *
 * This function prints the environment variables to stdout,
 * then releases memory allocated for the command and sets the status to 0.
 */
void print_env(char **command, int *status)
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray2D(command);
	*status = 0;
}
