#include "../shell.h"
#include <unistd.h>

/**
 * builtin_env- custom env built-in. prints environment variables
 * @cmd: command struct
 * Return: exit status
 **/
int builtin_env(command_t *cmd)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FD, environ[i], _strlen(environ[i]));
		write(STDOUT_FD, "\n", 1);
	}

	(void)cmd;
	return (0);
}

/**
 * help_env - prints environment help content
 **/
void help_env(void)
{
	int i;
	char *lines[] = {
		"env: env",
		"\tPrint a list of the enviornment.",
		NULL};

	for (i = 0; lines[i]; i++)
		_puts(lines[i]);
}
