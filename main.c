#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int ac, char **av)
{

	//01000001
	
	int pid = atoi(av[ac - 1]);
	char c = 'A';
	int result;

	int i = 7;

	while (i >= 0)
	{
		result = (c >> i) & 1;
		if (result == 0)
			kill(pid, SIGUSR2);
		else if (result == 1)
			kill(pid, SIGUSR1);
		usleep(10);
		i--;
	}
	return 0;
}
