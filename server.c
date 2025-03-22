/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:29:08 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/22 23:29:57 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void printnum(int nbr)
{
	unsigned int n;
	char c; 

	if (nbr < 0)
	{
		write (1, "-", 1);
		n = nbr;
	}
	else
		n = nbr;
	if (n > 9)
		printnum(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	signal_handler(int signum)
{
	static char	c = 0;
	static int	bit = 7;

	if (signum == SIGUSR2)
		c = c | (1 << bit);
	if (bit == 0)
	{
		write(1, &c, 1);
		c = 0;
		bit = 8;
	}
	bit--;
}

int	main(void)
{
	write (1, "Server PID NUM : ", 17);
	printnum(getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
