/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leali-ha <leali-ha@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:06:29 by leali-ha          #+#    #+#             */
/*   Updated: 2025/07/21 14:15:46 by leali-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_client.h"

void	use_less(int n)
{
	(void) n;
}

void	send_signal(char c, pid_t pid)
{
	int		count;

	count = 0;
	while (count < 8)
	{
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c / 2;
		count++;
	}
}

void	run_client(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signal(str[i], pid);
		i++;
		signal(SIGUSR1, use_less);
		pause();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	run_client(argv[1], ft_atoi(argv[1]));
}
