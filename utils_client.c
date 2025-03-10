/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:32:37 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/08 14:33:17 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	send_bit(char bit, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((bit >> i) & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "kill failed!!!\n", 15);
				exit (1);
			}
		}
		else if (((bit >> i) & 1) == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "kill failed!!!\n", 15);
				exit (1);
			}
		}
		usleep(500);
		i--;
	}
}
