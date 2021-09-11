/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_interrupt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:49:31 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 02:18:07 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft/stream/stream.h>
#include <libft/io/printf.h>
#include <libft/io/util/ansidefs.h>

#include <minitalk/server/output.h>

void	handle_interrupt(int signal)
{
	t_stream	*sout;

	(void)signal;
	sout = get_output_stream();
	ft_stream_close(sout);
	ft_xprintf(ANSI_F_MAGENTA "\nSee you next time 🗿\n" ANSI_RESET);
	exit(0);
}
