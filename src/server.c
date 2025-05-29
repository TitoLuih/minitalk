/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:31:37 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/29 19:09:08 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signal)
{
	
}

int	main (void)
{
	signal (SIGUSR1, handler);
	signal (SIGUSR2, handler);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
