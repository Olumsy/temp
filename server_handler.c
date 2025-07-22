/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leali-ha <leali-ha@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:36:45 by leali-ha          #+#    #+#             */
/*   Updated: 2025/07/21 21:51:36 by leali-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_server.h"
#include <stdio.h>

void	sig_handler(int	sig_num, siginfo_t *info_sig, void *ucontext)
{
	static char	*str;
	static int	count = 0;
	static int	i = 0;
	static int	alloc_size = 2;

	(void) ucontext;
	ft_putstr_fd("roger\n", 1);
	printf("%d", info_sig->si_pid);
	fflush(stdout);

	if (!str)
		str = ft_calloc(sizeof(char), alloc_size);
	str[i] += sig_num;
	str[i] *= 2;
	count++;
	if (count % 8 == 0)
		i++;
	if (str[i] == '\0')
	{
		ft_putstr_fd(str, 1);
		free(str);
		str = NULL;
		count = 0;
		i = 0;
		alloc_size = 2;
	}
	if (count == alloc_size * 8)
	{
		ft_realloc(str, alloc_size + 1);
		alloc_size *= 2;
	}
	usleep(1200);
	kill(info_sig->si_pid, SIGUSR1);
}
