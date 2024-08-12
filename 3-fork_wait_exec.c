#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	int status;
	int i;

	char *argv[] = {"/bin/ls","-l","/tmp",NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			printf("Number of child process created : %d\n", i+1);
			
			if (execve(argv[0], argv, NULL) == 1)
			{
				perror("Error executing execve");
				return (1);
			}
		}
		else
		{
			wait(&status);
			printf("Child process Number : %d is terminated\n", i+1);
		}
	}
	return (0);
}
