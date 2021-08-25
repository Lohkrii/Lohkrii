#ifndef HOLBERTON_H_
#define HOLBERTON_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>


/******** env_func **********/
void env_out(char *buffer, char **args, char **env);
void _error(char **argv, char *arg, int amt);

/******** free_func *********/
void free_arr(char **arr);
void parent_free(char *buffer, char **args);

/******** help_func *********/
unsigned int _strlen( char *buffer);
char *_strtok(char *str);
unsigned int count_args(char *star);
char *_strcopy(char *dest, char *src, int amt);
int _atoi(char *arg);

/******** path_func **********/
void find_path(char **args, char *buffer, char **env, char **argv, int amt);

/******** process_func *******/
void _fork(char **args, char **argv, char **env, char **buffer, int amt);


/***** Missing func ******/
char **env_var(char *cmd, char **environ);
unsigned int find_dir(char *path);
char *_getenv(const char *key, char **environ);
char print_env(char **environ);
char *_strncpycmd(char *dest, char *src, char *cmd, int n, int c);
char *_strncopyconst(char *dest, const char *src, int n);
unsigned int _strlenconst(const char *name);
int _strcmp(char *s1, char *s2);
void fork_fail(void);
void cmd_null(char *buffer);

#endif // HOLBERTON_H_
