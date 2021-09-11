/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:20:18 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 02:08:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <inttypes.h>

#include <libft/io/printf.h>
#include <libft/io/util/ansidefs.h>
#include <libft/types.h>

#include <minitalk/client/client.h>
#include <minitalk/client/signal_handling.h>

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	register_signal_handlers();
	if (argc != 3)
	{
		ft_xprintf("Usage: %s <pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 0 || send_message(server_pid, argv[2]) == -1)
	{
		ft_xdprintf(
			STDERR_FILENO,
			ANSI_F_RED "Error: Unable to send signal\n" ANSI_RESET
			);
		return (2);
	}
	return (0);
}
