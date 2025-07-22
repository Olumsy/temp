/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leali-ha <leali-ha@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:22:10 by leali-ha          #+#    #+#             */
/*   Updated: 2025/07/21 14:39:58 by leali-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_client.h"

void	write_pid()
{
	char	*server_pid;

	server_pid = ft_itoa(getpid());
	ft_putstr_fd(server_pid, 1);
	free(server_pid);
	write(1, &server_pid, 1);
}

void	run_server()
{
	struct	sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write_pid();
	while (42 == 42)
	{
		pause();
	}
}

int	main()
{
	run_server();
}
