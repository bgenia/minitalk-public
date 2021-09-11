/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:42:34 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 00:43:45 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk/client/signal_status.h>

volatile t_signal_status	g_signal_status = {
	.processed = false,
	.received = false
};
