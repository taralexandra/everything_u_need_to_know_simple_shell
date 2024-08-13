#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	char *env_var;

	while (environ[i] != NULL)
	{
		env_var = environ[i];

		if (strncmp(env_var, name, strlen(name)) == 0 && env_var[strlen(name)] == '=')
		{
			return env_var + strlen(name) + 1;
		}
		i++;
	}
	return (NULL);
}

void print_path_directories(void)
{
	char *path = _getenv("PATH");
	char *token;

	if (path == NULL)
	{
		printf("PATH not found.\n");
		return;
	}

	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	free(path_copy);
}

int main(void)
{
	print_path_directories();
	return (0);
}
