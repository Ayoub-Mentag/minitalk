/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amentag <amentag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:40:19 by amentag           #+#    #+#             */
/*   Updated: 2023/01/02 13:40:22 by amentag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_stop(void)
{
	write(2, "The pid is not correct\n", 23);
	exit(1);
}

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
		ft_stop();
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
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
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	main(int ac, char **av)
{
	int	result;
	int	i;
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[ac - 2]);
		if (pid <= 0)
			ft_stop();
		while (*av[ac - 1])
		{
			i = 8;
			while (i--)
			{
				result = ((*av[ac - 1]) >> i) & 1;
				if (result == 1)
					send_signal(pid, SIGUSR1);
				else if (result == 0)
					send_signal(pid, SIGUSR2);
				usleep(700);
			}
			av[ac - 1]++;
		}
	}
	return (0);
}
