#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * unsetenv - the goal is to erase an environment variable.
  * @name: The name of the environment variable to eradicate.
  *
  * Return: 0 in case of success and -1 for a failure.
  */
int _unsetenv(const char *name)
{
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
    {
        return -1;
    }

    extern char **environ;
    int len = strlen(name);
    char **env = environ;
    char **to_remove = NULL;

    while (*env != NULL)
    {
	    if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
        {
            to_remove = env;

	    while (*env != NULL)
            {
                *env = *(env + 1);
                env++;
            }
	    break;
        }
        env++;
    }

    if (to_remove == NULL)
    {
        return -1;
    }

    return 0;
}

/**
  * The main function.
  */

int main(void)
{
	setenv("TEST_VAR", "123", 1);
	printf("TEST_VAR before unsetting : %s\n", getenv("TEST_VAR"));

	_unsetenv("TEST_VAR");
	printf("TEST_VAR after the unset: %s\n", getenv("TEST_VAR"));

	return (0);
}
