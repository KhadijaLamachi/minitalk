/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:44:55 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/08 15:50:18 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		putstr("invalid PID!!!\n");
		return (1);
	}
	while (argv[2][i])
	{
		send_bit(argv[2][i], pid);
		i++;
	}
	return (0);
}
