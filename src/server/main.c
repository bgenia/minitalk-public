/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:20:20 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 02:35:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/io/printf.h>
#include <libft/io/util/ansidefs.h>

#include <minitalk/server/signal_handling.h>
#include <minitalk/server/server.h>

int	main(void)
{
	register_signal_handlers();
	ft_xprintf(
		ANSI_F_MAGENTA "Minitalk server is listening on pid: "
		ANSI_F_GREEN "%d\n"
		ANSI_F_MAGENTA "Use " ANSI_F_YELLOW "SIGINT" ANSI_F_MAGENTA " to exit\n"
		ANSI_RESET,
		getpid()
		);
	server_loop();
}
