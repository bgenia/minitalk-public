/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:44:43 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 01:13:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <libft/io/printf.h>

#include <minitalk/client/signal_status.h>

void	handle_status(int signal)
{
	if (signal == SIGUSR1)
		status_set_received();
	if (signal == SIGUSR2)
		status_set_processed();
}
