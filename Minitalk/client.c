/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-l <rlopez-l@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:27:15 by rlopez-l          #+#    #+#             */
/*   Updated: 2023/11/14 14:48:04 by rlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_mt	*client_ini(void)
{
	t_mt	*msg;

	msg = malloc(sizeof(t_mt));
	if (!msg)
	{
		ft_putst("ERROR, malloc failed.(!\n)");
		exit(EXIT_FAILURE);
	}
	msg->pid_server = 0;
	msg->pid_client = 0;
	return (msg);
}

void	client_send(t_mt *msg, char *c)
{
	int		bit;
	size_t	i;
	int		signal;

	i = -1;
	while (++i <= ft_strlen(c))
	{
		bit = -1;
		signal = 0;
		while (++bit < 7)
		{
			if (c[i] >> bit & 1)
			{
				signal = SIGUSR2;
			}
			else
				signal = SIGUSR1;
			kill(msg->pid_server, signal);
			usleep(200);
		}
	}
	return ;
}

int	main(int words, char *arg[])
{
	t_mt	*msg;

	msg = NULL;
	if (words != 3)
	{
		ft_putst("ERROR, we need 3 arguments \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		msg = client_ini();
		msg->pid_server = ft_atoi(arg[1]);
		if (msg->pid_server <= 0)
		{
			ft_putst("ERROR, PID is not correct \n");
			free(msg);
			exit(EXIT_FAILURE);
		}
		client_send(msg, arg[2]);
	}
	free(msg);
	return (EXIT_SUCCESS);
}
