#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _setenv - Changes or adds an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set the environment variable to.
 * @overwrite: Whether to overwrite an existing value (1 to overwrite, 0 to not).
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || value == NULL || name[0] == '\0')
    {
        return -1;
    }

    char *current_value = getenv(name);

    if (current_value != NULL && overwrite == 0)
    {
        return 0;
    }

    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    char *new_env_var = malloc(name_len + value_len + 2);

    if (new_env_var == NULL)
    {
        return -1;
    }

    strcpy(new_env_var, name);
    strcat(new_env_var, "=");
    strcat(new_env_var, value);

    if (putenv(new_env_var) != 0)
    {
        free(new_env_var); 
	return -1;
    }

    return 0;
}

/**
  * Fonction main.
  */

int main(void)
{
    _setenv("MY_VAR", "42", 1);
    printf("MY_VAR: %s\n", getenv("MY_VAR"));

    _setenv("MY_VAR", "100", 0); 
    printf("MY_VAR: %s\n", getenv("MY_VAR"));

    _setenv("MY_VAR", "100", 1); 
    printf("MY_VAR: %s\n", getenv("MY_VAR"));

    return 0;
}

