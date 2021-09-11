/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 00:46:20 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 01:37:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLING_H
# define SIGNAL_HANDLING_H

# include <signal.h>

void
register_signal_handlers(void);

void
handle_interrupt(int signal);

void
handle_data(int signal, siginfo_t *info, void *context);

#endif
