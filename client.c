/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:44:55 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/06 09:43:42 by klamachi         ###   ########.fr       */
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

void	send_bit(char bit)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((bit >> i) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((bit >> i) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		putstr("usage: ./client <pid> <message>\n");
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		putstr("invalid PID\n!!!");
		return (1);
	}
	while (argv[2][i])
	{
		send_bit(argv[2][i])
		i++;
	}
	return (0);
}
