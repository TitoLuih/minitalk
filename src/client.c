/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:31:28 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/30 12:11:29 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(int pid, char msg)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((msg & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int		p_id;
	int		i;

	if (argc != 3)
	{
		ft_printf("Maybe try <PID> <Message>");
		exit(0);
	}
	p_id = ft_atoi(argv[1]);
	i = 0;
	while (argv[2])
	{
		send_signal(p_id, argv[2][i]);
		i++;
	}
	send_signal(p_id, '\0');
	return (EXIT_SUCCESS);
}
