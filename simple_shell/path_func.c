#include "holberton.h"
/**
 * find_path - 
 * @amt:
 * @args:
 * @argv:
 * @buffer:
 * @env:
 */
void find_path(char **args, char *buffer, char **env, char **argv, int amt)
{
	struct stat Stat;;
	int idx;
	char **dir;

	idx = 0;
	dir = env_var(args[0], env);
	
	while (dir[idx])
	{
		if (stat(dir[idx], &Stat) == 0)
			execve(dir[idx], args, NULL);
		++idx;
	}

	/* If no command found, print error message */
	_error(argv, args[0], amt);

	free(buffer);
	free_arr(args);
	free_arr(dir);
	exit(EXIT_SUCCESS);
}
