/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_set_received.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:35:37 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 00:36:09 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk/client/signal_status.h>

void	status_set_received(void)
{
	g_signal_status.received = true;
}
