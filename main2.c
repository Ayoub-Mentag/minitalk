#include <stdio.h>
#include <signal.h>
#include <unistd.h>

char c = 0;
int i = 0;
void	handler(int num)
{
	if (num == SIGUSR1)
		c = (c << i) + 1;
	else if (num == SIGUSR2)
		c = (c << i);
	i++;
}

int main()
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("pid : %d\n", getpid());
	printf("%c", c);
	while (1);
	return 0;
}
