/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:01:42 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/23 16:37:07 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	signal_handler(int signum);
long	ft_atoi(char *str);
void	send_bit_and_wait(int pid, int bit);
void	send_bit(int pid, char c);
void	check_pid(char *str);
void	printnum(int nbr);

#endif