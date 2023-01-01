#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int ac, char **av)
{

	//01000001
	(void)ac;
	int pid = atoi(av[1]);
	char c;
	int result;

	int i;
	
	while (*av[2])
	{
		c = *av[2];
		i = 7;
		while (i >= 0)
		{
			result = (c >> i) & 1;
			if (result == 1)
				kill(pid, SIGUSR1);
			else if (result == 0)
				kill(pid, SIGUSR2);
			i--;
			usleep(800);
		}
	}
	return 0;
}
