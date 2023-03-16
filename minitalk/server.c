/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:17:10 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/01/19 10:17:11 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_print_msg(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	(void) argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr_fd("PID: ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putstr_fd("\n", 1);
		while (1)
		{
			signal(SIGUSR1, ft_print_msg);
			signal(SIGUSR2, ft_print_msg);
			pause();
		}
	}
	else
		ft_putstr_fd("--ERROR-- TRY: <./server>\n", 1);
}
