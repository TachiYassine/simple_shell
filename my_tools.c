#include "shell.h"

/**
 * freearray2D - Frees memory allocated for a 2D array.
 *
 * @arr: Pointer to the 2D array to be deallocated.
 *
 * This function deallocates memory previously allocated for a 2D array.
 */
void freearray2D(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}

/**
 * print_error - Prints an error message.
 *
 * @name: Pointer to the name or identifier related to the error.
 * @cmd: Pointer to the command associated with the error.
 * @idx: Integer representing an index or specific info related to error
 *
 * This function prints an error message indicating an issue or failure,
 * including relevant details such as the name, command, and index.
 */
void print_error(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}

/**
 * _itoa - Converts an integer to a string.
 *
 * @n: The integer value to be converted to a string.
 *
 * Return: Pointer to a string representing the integer value.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_Str_duplicate(buffer));
}

/**
 * reverse_string - Reverses characters in a string up to a specified length.
 *
 * @str: Pointer to the string to be reversed.
 * @len: Length up to which the string should be reversed.
 *
 * This function reverses characters in the string to the specified length
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
