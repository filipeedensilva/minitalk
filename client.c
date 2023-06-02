/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:46:05 by feden-pe          #+#    #+#             */
/*   Updated: 2023/06/01 18:56:22 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, char a)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (a & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(150);
	}
}

void	send_len(int pid, int len)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if (len & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(150);
	}
}

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message received by the server\n");
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	len;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		len = ft_strlen(av[2]);
		signal(SIGUSR1, handle_sig);
		send_len(pid, len);
		while (av[2][i])
			send_sig(pid, av[2][i++]);
		send_sig(pid, '\0');
	}
	else {
		ft_printf("Invalid number of arguments\n Usage: ./client 'PID' 'message'\n");
	}
	return (0);
}
