/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amentag <amentag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:40:45 by amentag           #+#    #+#             */
/*   Updated: 2023/01/02 14:32:04 by amentag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void	handler(int num, siginfo_t *info, void *ptr)
{
	static unsigned char	c;
	static int				pid;
	static int				i = 7;

	(void)ptr;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 7;
		c = 0;
	}
	if (num == SIGUSR1)
		c += (1 << i);
	i--;
	if (i == -1)
	{
		write(1, &c, 1);
		if (c == 0)
			kill(pid, SIGUSR1);
		i = 7;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;

	(void)av;
	if (ac == 1)
	{
		action.sa_sigaction = handler;
		action.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		write(1, "pid : ", 6);
		ft_putnbr(getpid());
		write(1, "\n", 1);
		while (1)
			pause();
	}
	return (0);
}
