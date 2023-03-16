/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassa-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:17:02 by mmassa-r          #+#    #+#             */
/*   Updated: 2023/01/19 10:17:04 by mmassa-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_bits(int pid, char *str)
{
	int	index;
	int	bit;

	index = 0;
	while (str[index])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (str[index] >> bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit--;
		}
		index++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_bits(pid, argv[2]);
		ft_bits(pid, "\n");
	}
	else
		ft_putstr_fd("ERROR: TRY: ./client <PID> <STRING>\n", 1);
}
