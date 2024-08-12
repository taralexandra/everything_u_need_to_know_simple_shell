#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t stock_parent_pid;

	stock_parent_pid = getppid();

	printf("Parent PID is: %u\n", stock_parent_pid);

	return (0);

}
