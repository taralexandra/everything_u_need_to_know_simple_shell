#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) 
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
pid_t child_pid;
int status;

while (1)
{
	printf("#shell$ ");

	nread = getline(&line, &len, stdin);
	
	if (nread == -1)
	{
		perror("getline");
		break;
	}

	line[nread - 1] = '\0';

	if (strcmp(line, "exit") == 0) 
	{ 
		break; 
	}

	child_pid = fork();
	
	if (child_pid == -1)
	{
		perror("fork");
		continue;
	}

	if (child_pid == 0)
	{
		char *argv[] = {line, NULL};
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
		}

		return (1);
	}
	else
	{
		wait(&status);
	}

}

free(line);
return (0);

}
