# "holberton.h"
/**
 * _fork - Creates a forked process
 * @args: List of arguments
 * @argv: starting arguments
 * @env: Environment variable list
 * @buffer: User input
 * @amt: While count
 */
void _fork(char **args, char **argv, char **env, char **buffer, int amt)
{
	int child_status;
	pid_t pid;
	struct stat fStat; // verify f

	pid = fork();
	if(pid == -1)
	{
		perror("Error;");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		if(args == NULL)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp("exit", args[0])) //probar con strncmp para comparar los bytes necesarios.
			exit_out(buffer, args);
		else if (_strcmp("env", args[0]))
			env_out(buffer, args, env);
		else if (stat(args[0], &fStat) == 0)
			execve(args[0], args, NULL);
		else
			c_path(args, buffer,env, argv, count);
	}
	else
	{
		wait(&child_status);
		if(args == NULL)
			parent_free(buffer, args);
		else if(_strcmp("exit", args[0]))
			exit_out(buffer, args);
		else
			parent_free(buffer, args);
	}
}

/**
 * exit_out -
 * @buffer:
 * @cmd
 */
void exit_out(char *buffer, char **args)
{
	int status = 0;

	if (args[1] != NULL) //siempre y cuando args[1] no sea igual a nulo, (ls) solo seria args nulo.
	{
		status = _atoi(args[1]); //atoi convierte de caracter a integers.
	}
	free(buffer);
	free_arr(args);
	exit(status);
}
