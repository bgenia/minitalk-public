/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_await.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:23:31 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 00:35:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk/client/signal_status.h>

void	status_await(void)
{
	while (
		!g_signal_status.processed
		|| !g_signal_status.received
	);
}
