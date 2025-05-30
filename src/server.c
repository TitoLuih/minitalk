/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-to <lruiz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:31:37 by lruiz-to          #+#    #+#             */
/*   Updated: 2025/05/30 11:58:56 by lruiz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	character;
	static int	counter;

	counter = 0;
	if (signal == SIGUSR1)
		character |= (1 << counter);
	counter++;
	if (counter == 8)
	{
		if (character == '\0')
			write (1, "\n", 1);
		else
			write (1, &character, 1);
		counter = 0;
		character = 0;
	}
}

int	main(void)
{
	signal (SIGUSR1, handler);
	signal (SIGUSR2, handler);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
