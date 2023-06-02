/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:51:35 by feden-pe          #+#    #+#             */
/*   Updated: 2023/06/01 18:54:52 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_len(int sig, siginfo_t *info, void *context);
void	handle_sig(int sig, siginfo_t *info, void *context);

typedef struct s_var
{
	struct sigaction	sa;
	int			len;
	int			cpid;
	char			*str;
}	t_var;

static t_var	g_var;

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
		if (c == '\0')
		{
			write(1, g_var.str, g_var.len);
			free(g_var.str);
			g_var.len = 0;
			g_var.sa.sa_sigaction = receive_len;
			i = 0;
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		c = 0;
	}
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
		g_var.sa.sa_sigaction = handle_sig;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
		ft_printf("Invalid number of arguments\nUsage: ./server\n");
	else
	{
		pid = getpid();
		ft_printf("Server PID: %d\nOn standby for a message...\n", pid);
		g_var.sa.sa_sigaction = receive_len;
		g_var.sa.sa_flags = SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &g_var.sa, 0);
			sigaction(SIGUSR2, &g_var.sa, 0);
			pause();
		}
	}
	return (0);
}