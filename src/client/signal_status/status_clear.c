/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:23:31 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 01:05:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk/client/signal_status.h>

void	status_clear(void)
{
	g_signal_status.received = false;
	g_signal_status.processed = false;
}
