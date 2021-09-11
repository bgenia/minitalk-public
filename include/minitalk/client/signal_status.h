/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_status.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:32:46 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 00:39:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_STATUS_H
# define SIGNAL_STATUS_H

# include <stdbool.h>

typedef struct s_signal_status
{
	bool	received;
	bool	processed;
}	t_signal_status;

extern volatile t_signal_status	g_signal_status;

void
status_clear(void);

void
status_await(void);

void
status_set_received(void);
void
status_set_processed(void);

#endif
