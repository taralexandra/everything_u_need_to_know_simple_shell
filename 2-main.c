#include "split_string.h"

int main(void)
{
	char **result;
	const char *test_str = "Hello world example string";

	result = split_string(test_str);

	if (result == NULL)
	{
		fprintf(stderr, "Failed to split string\n");
		return 1;
	}

	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i, result[i]);
	}

	free_split_string(result);
	return 0;
}
