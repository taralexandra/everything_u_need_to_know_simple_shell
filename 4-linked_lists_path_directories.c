#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct path_node
{
	char *directory;
	struct path_node *next;
} path_node_t;

/**
  * add a node to the list
  */
path_node_t *add_node(path_node_t **head, const char *directory)
{
	path_node_t *new_node = malloc(sizeof(path_node_t));

	if (new_node == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	new_node->directory = strdup(directory);

	if (!new_node->directory)
	{
		perror("strdup");
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		path_node_t *temp = *head;

		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}

	return new_node;
}

/**
  * build the linked list from path
  */
path_node_t *build_path_list(void)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH not found.\n");
		return (NULL);
	}
	path_node_t *head =  NULL;
	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		add_node(&head, token);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (head);
}

/**
  * the function to display the linked list
  */
void print_path_list(path_node_t *head)
{
	path_node_t *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}
}

/**
  * the main function.
  */
int main(void)
{
	path_node_t *path_list = build_path_list();

	if (path_list != NULL)
	{
		print_path_list(path_list);
	}
	return (0);
}
/**
  * free memory to avoid memory leaks
  */
void free_path_list(path_node_t *head)
{
	path_node_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->directory);
		free(temp);
	}
}
