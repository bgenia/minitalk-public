/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:45:57 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 01:28:17 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <signal.h>

#include <minitalk/client/signal_handling.h>

typedef struct sigaction	t_sigaction;

void	register_signal_handlers(void)
{
	t_sigaction	action_recieve_status;

	action_recieve_status = (t_sigaction){0};
	action_recieve_status.sa_handler = handle_status;
	sigaction(SIGUSR1, &action_recieve_status, NULL);
	sigaction(SIGUSR2, &action_recieve_status, NULL);
}
