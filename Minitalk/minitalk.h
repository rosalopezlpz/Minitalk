/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-l <rlopez-l@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:27:54 by rlopez-l          #+#    #+#             */
/*   Updated: 2023/11/14 14:24:54 by rlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "minilib/minilib.h"
# include <sys/types.h>
# include <signal.h>

typedef struct s_mt
{
	int	pid_server;
	int	pid_client;
}	t_mt;

t_mt	*client_ini(void);
t_mt	*server_ini(void);
void	client_send(t_mt *msg, char *c);
void	server_receive(int sign);

#endif
