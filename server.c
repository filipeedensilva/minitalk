/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                      |  _____|_____   |  |      */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:51:35 by feden-pe          #+#    #+#             */
/*   Updated: 2023/06/15 17:13:05 by fede     |__|     |_______| |__| |__|    */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void	receive_len(int sig, siginfo_t *info, void *context);
void	handle_sig(int sig, siginfo_t *info, void *context);
void	print_message(void);

typedef struct s_var
{
	struct sigaction	sg;
	int					len;
	char				*str;
}	t_var;

static t_var	g_var;

void	print_message(void)
{
	write(1, g_var.str, g_var.len);
	write(1, "\n", 1);
	free(g_var.str);
	g_var.len = 0;
	g_var.sg.sa_sigaction = receive_len;
}


void	receive_len(int sig, siginfo_t *info, void *context)
{
	static int	bit;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_var.len |= 1 << bit;
	else
		g_var.len |= 0 << bit;
	bit++;
	if (bit == 32)
	{
		g_var.str = (char *)malloc(sizeof(char) * g_var.len + 1);
		g_var.sg.sa_sigaction = handle_sig;
		bit = 0;
	}
}

void	handle_sig(int sig, siginfo_t *info, void *content)
{
	static int	bit;
	static char	c;
	static int	i;

	(void)content;
	if (sig == SIGUSR1)
		c |= 1 << bit;
	else
		c |= 0 << bit;
	bit++;
	if (bit == 8)
	{
		g_var.str[i++] = c;
		if (i + 1 == g_var.len)
		{
			print_message();
			i = 0;
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
		ft_printf("Incorrect number of arguments!\nUsage: ./server\n");
	else
	{
		pid = getpid();
		ft_printf("PID: %d\nOn standby for message...\n", pid);
		g_var.sg.sa_sigaction = receive_len;
		g_var.sg.sa_flags = SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &g_var.sg, 0);
			sigaction(SIGUSR2, &g_var.sg, 0);
			pause();
		}
	}
	return (0);
}
