#include "holberton.h"

/**
 * main - A simple shell to pass through commands.
 * Return: 0.
 */
int main(int argc, char **argv, char **env)
{
	char *buffer;//buffer lo guarda todo
	char **args;
	size_t bufsize; //contiene lo que queremos de buffer
	size_t input;// recoge el resultado de getline
	unsigned int len; //contiene el largo de buffer
	(void)argc; //indeclarando la variable argc
	int check = isatty;

	check = isatty(STDIN_FILENO);
	if (check != NULL)
		write(1, "\nCHAMPIONS$", 10);
	
	while (input = getline(&buffer, bufsize, stdin))
	{
		if (input == EOF)
		{
			free(buffer);
			exit(0);
		}
		idx++;
		
		args = _strtok(buffer);
		_fork(args, argv, env, buffer, idx);

		bufsize = 0;
		if (isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, "Champions $", 2);
		buffer = NULL;
	}
	if (input == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
