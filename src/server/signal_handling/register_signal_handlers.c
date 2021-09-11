/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:45:57 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 02:02:05 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <signal.h>

#include <minitalk/server/signal_handling.h>

typedef struct sigaction	t_sigaction;

void	register_signal_handlers(void)
{
	t_sigaction	action_interrupt;
	t_sigaction	action_data;

	action_interrupt = (t_sigaction){0};
	action_interrupt.sa_handler = handle_interrupt;
	sigaction(SIGINT, &action_interrupt, NULL);
	action_data = (t_sigaction){0};
	action_data.sa_flags = SA_SIGINFO;
	action_data.sa_sigaction = handle_data;
	sigaction(SIGUSR1, &action_data, NULL);
	sigaction(SIGUSR2, &action_data, NULL);
}
