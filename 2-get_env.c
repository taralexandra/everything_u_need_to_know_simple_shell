#include <stdio.h>
#include <string.h>

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

int main(void)
{
	char *value = _getenv("PATH");

	if (value != NULL)
	{
		printf("PATH: %s\n", value);
	}
	else
	{
		printf("PATH not found.\n");
	}

	return (0);
}
