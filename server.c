#include <stdio.h>
#include <signal.h>
#include <unistd.h>

char c = 0;
int i = 7;
void	handler(int num)
{
	if (num == SIGUSR1)
		c += (1 << i);
	i--;
	if (i == -1)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

int main()
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("pid : %d\n", getpid());
	while (1);
	return 0;
}
