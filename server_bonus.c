/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:10:52 by raljaber          #+#    #+#             */
/*   Updated: 2024/05/27 18:28:28 by raljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("The server's PID is: %d\n", pid);
	act.sa_sigaction = ft_btoa;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
