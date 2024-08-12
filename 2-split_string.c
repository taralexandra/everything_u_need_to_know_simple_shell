#include "split_string.h"

char **split_string(const char *str)
{
	char **result = NULL;
	char *token;
	char *str_copy;
	int count = 0;
	int i;

	str_copy = strdup(str);

	if (str_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(str_copy, " ");

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}

	result = malloc((count + 1) * sizeof(char *));

	if (result == NULL)
	{
		perror("malloc");
		free(str_copy);
		return (NULL);
	}

	strcpy(str_copy, str);
	token = strtok(str_copy, " ");
	i = 0;

	while (token != NULL)
	{
		result[i] = strdup(token);

		if (result[i] == NULL)
		{
			perror("strdup");

			for (int j = 0; j < i; j++)
			{
				free(result[j]);
			}

			free(result);
			free(str_copy);
			return (NULL);
		}

		i++;
		token = strtok(NULL, " ");
	}

	result[i] = NULL;
	free(str_copy);

	return (result);
}

void free_split_string(char **array)
{
	int i;

	if (array)
	{
		for (i = 0; array[i] != NULL; i++)
		{
			free(array[i]);
		}
		free(array);
	}
}

