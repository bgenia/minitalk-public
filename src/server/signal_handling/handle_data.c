/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:55:54 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 15:13:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <libft/stream/stream.h>

#include <minitalk/server/output.h>

void	handle_data(int signal, siginfo_t *info, void *context)
{
	static char	buffer = 0;
	static int	cursor = 0;
	t_stream	*sout;
	pid_t		sender;

	(void)context;
	sout = get_output_stream();
	sender = info->si_pid;
	if (signal == SIGUSR2)
		buffer |= 1 << cursor;
	kill(sender, SIGUSR1);
	cursor++;
	if (cursor == 8)
	{
		if (buffer != 0)
			ft_stream_write(sout, (char *)&buffer, 1);
		else
			ft_stream_flush(sout);
		cursor = 0;
		buffer = 0;
	}
	kill(sender, SIGUSR2);
}
