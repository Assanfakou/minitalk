/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:29:08 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/21 22:29:42 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
		00000001          00001001
      | 00101000        & 00101001
		00101001          00001001
*/
void check_pid(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			write (2, "PID incorrect\n", 14);
			exit(EXIT_FAILURE);
		}
	}
}
int	ft_atoi(char *str)
{
	size_t	res;
	int		i;
	int		signe;

	res = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (signe * res);
}

void	send_bit_and_wait(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(1600);
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
		printf("Usage: %s <PID> <message>\n", av[0]);
		return (1);
	}
	check_pid(av[1]);
	pid = ft_atoi(av[1]);
	if (pid == INT_MAX || pid == 0)
		return (1);
	i = 0;
	while (av[2][i])
	{
		send_bit(pid, av[2][i]);
		i++;
	}
	send_bit(pid, '\0');
	return (0);
}
