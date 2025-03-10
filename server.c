/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:44:49 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/08 14:35:39 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	(void)argc;
	(void)argv;
	pid = getpid();
	if (pid == -1)
		return (write(1, "getpid failed!!!\n", 17), 1);
	putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) == -1)
		return (write(1, "sigemptyset failed!!!\n", 22), 1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (write(1, "sigaction failed!!!\n", 20), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (write(1, "sigaction failed!!!\n", 20), 1);
	while (1)
		pause();
	return (0);
}
