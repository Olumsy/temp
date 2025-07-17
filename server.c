/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leali-ha <leali-ha@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:22:10 by leali-ha          #+#    #+#             */
/*   Updated: 2025/07/17 20:53:08 by leali-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_client.h"

void	run_server()
{
	struct	sigaction	sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	write_pid();
}

void	write_pid()
{
	pid_t	server_pid;

	server_pid = getpid();
	write(1, &server_pid, 1);
}

void	
