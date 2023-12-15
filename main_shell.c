#include "shell.h"

/**
 * main - Entry point of the program
 *
 * @ac: Number of arguments passed to the program
 * @av: Array of pointers to strings containing the arguments
 * @env: Array of pointers to strings containing the environment variables
 *
 * Return: 0.
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
