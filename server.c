/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:26:27 by raljaber          #+#    #+#             */
/*   Updated: 2024/05/25 16:00:08 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("The server's PID is: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
}
