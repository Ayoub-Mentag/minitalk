/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amentag <amentag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:40:31 by amentag           #+#    #+#             */
/*   Updated: 2023/01/02 14:41:19 by amentag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	g_pid;

void	ft_stop(void)
{
	write(2, "The pid is not correct\n", 23);
	exit(1);
}

void	handler(void)
{
	write(1, "The message was sent successfully\n", 34);
}

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
		ft_stop();
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 3)
	{
		signal(SIGUSR1, handler);
		g_pid = ft_atoi(av[ac - 2]);
		if (g_pid <= 0)
			ft_stop();
		while (1)
		{
			i = 8;
			while (i--)
			{
				if (((*av[ac - 1]) >> i) & 1 == 1)
					send_signal(g_pid, SIGUSR1);
				else
					send_signal(g_pid, SIGUSR2);
				usleep(700);
			}
			if (*av[ac - 1] == 0)
				break ;
			av[ac - 1]++;
		}
	}
	return (0);
}
