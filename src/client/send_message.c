/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:16:10 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 15:13:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <signal.h>

#include <libft/string/string.h>

#include <minitalk/client/client.h>
#include <minitalk/client/signal_status.h>

static int	send_bit(pid_t pid, char bit)
{
	int	result;

	status_clear();
	if (bit & 1)
		result = kill(pid, SIGUSR2);
	else
		result = kill(pid, SIGUSR1);
	if (result == -1)
		return (-1);
	status_await();
	return (0);
}

int	send_message(pid_t pid, char *message)
{
	size_t	i;
	int		j;

	i = 0;
	while (i <= ft_strlen(message))
	{
		j = 0;
		while (j < 8)
		{
			if (send_bit(pid, (message[i] >> j) & 1) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
