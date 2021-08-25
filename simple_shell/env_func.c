#include "holberton"
/**
 * env_out - 
 * @buffer:
 * @args:
 * @env:
 */
void env_out(char *buffer, char **args, char **env)
{
	free(buffer);
	free_arr(args);
	env_cmd(env);
	exit(EXIT_SUCCESS);
}

/**
 * _error - Prints error messages.
 * @argv: List of init arguments.
 * @arg: Arg error.
 * @amt: 
 *
 */
void _error(char **argv, char *arg, int amt)
{
	int temp, len, cpy = amt;
	char err;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);

	temp = 1;
	for (len = 1; cpy >= 10; len++)
	{
		cpy /= 10;
		temp *= 10;
	}

	while (len > 1)
	{
		if ((amt / temp) < 10)
			_puterror((amt / temp + '0'));
		else
			_puterror((amt / tmp) % 10 + '0');
		len--;
		temp /= 10;
	}

	err = amt % 10 + '0';
	write(STDERR_FILENO, &err, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arg, _strlen(arg));
	write(STDERR_FILENO, ": not found\n", 12);
}

