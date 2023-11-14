/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-l <rlopez-l@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:27:32 by rlopez-l          #+#    #+#             */
/*   Updated: 2023/11/14 14:50:27 by rlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_mt	*server_ini(void)
{
	t_mt	*msg;

	msg = malloc(sizeof(t_mt));
	if (!msg)
	{
		ft_putst("ERROR, malloc failed. \n");
		exit(EXIT_FAILURE);
	}
	msg->pid_server = 0;
	msg->pid_client = 0;
	return (msg);
}

void	server_receive(int sign)
{
	static int	bit = 0;
	static char	ch = 0;

	ch += ((sign & 1) << bit++);
	if (bit == 7)
	{
		write(1, &ch, 1);
		if (!ch)
			write(1, "\n", 1);
		bit = 0;
		ch = 0;
	}
	return ;
}

void	server_signal(t_mt *msg)
{
	while (1)
	{
		if ((signal(SIGUSR1, server_receive) == SIG_ERR)
			|| (signal(SIGUSR2, server_receive) == SIG_ERR))
		{
			ft_putst("ERROR, signal failure \n");
			free(msg);
			exit(EXIT_FAILURE);
		}
		sleep(2);
	}
	return ;
}

int	main(int words, char *args[])
{
	t_mt	*msg;

	(void) args;
	msg = NULL;
	if (!words)
	{
		ft_putst("ERROR, we need at least an argument.");
		exit(EXIT_FAILURE);
	}
	else
	{
		msg = server_ini();
		msg->pid_server = getpid();
		ft_putst("Server is ready, your PID is:");
		ft_putnbr(msg->pid_server);
		write(1, "\n", 1);
		server_signal(msg);
	}
	free(msg);
	return (EXIT_SUCCESS);
}
