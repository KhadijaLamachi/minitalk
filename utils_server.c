/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:31:58 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/08 14:34:16 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	g_c = 0;

void	putnbr(int nb)
{
	int	res;

	res = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 0 && nb <= 9)
	{
		res = nb + '0';
		write(1, &res, 1);
		return ;
	}
	putnbr(nb / 10);
	putnbr(nb % 10);
}

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	count = 0;
	static int	old_pid = 0;

	(void)context;
	if (info->si_pid != old_pid)
	{
		g_c = 0;
		count = 0;
		old_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
		g_c = g_c << 1;
	else if (signum == SIGUSR2)
		g_c = (g_c << 1) | 1;
	count++;
	if (count == 8)
	{
		write(1, &g_c, 1);
		g_c = 0;
		count = 0;
	}
}
