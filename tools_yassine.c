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
