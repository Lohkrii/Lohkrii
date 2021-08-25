#include "holberton.h "

/**
 * free_arr - Frees arrays.
 * @farr: The array to free
 */
void free_arr(char **arr)
{
	int idx;

	if(arr == NULL)
		return;

	for (idx = 0; arr[idx] != NULL; idx++)
		free(arr[idx]);

	free(arr);
}

/**
 * parent_free -
 * @buffer:
 * @args:
 */
void parent_free(char *buffer, char **args)
{
	free(buffer);
	free_arr(args);
}
