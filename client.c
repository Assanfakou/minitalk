/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:29:08 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/28 20:01:35 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			write(2, "PID incorrect\n", 14);
			exit(EXIT_FAILURE);
		}
	}
}

long	ft_atoi(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res >= INT_MAX)
			return (INT_MAX);
		i++;
	}
	return (res);
}

void	send_bit_and_wait(int pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
	}
	usleep(400);
}

void	send_bit(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		send_bit_and_wait(pid, (c >> bit) & 1);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		write(2, "Usage: <Program name> <PID> <message>\n", 39);
		exit(EXIT_FAILURE);
	}
	check_pid(av[1]);
	pid = ft_atoi(av[1]);
	if (pid == INT_MAX || pid == 0)
	{
		write(2, "PID incorrect\n", 14);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (av[2][i])
	{
		send_bit(pid, av[2][i]);
		i++;
	}
	send_bit(pid, '\0');
	return (0);
}
