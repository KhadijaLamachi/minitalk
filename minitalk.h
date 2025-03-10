/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:44:34 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/07 00:11:36 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(char *str);
void	ft_handler(int signum, siginfo_t *info, void *context);
void	putnbr(int nb);
void	putstr(char *str);
void	send_bit(char bit, int pid);

#endif
