/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output_stream.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:45:50 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 15:13:17 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/stream/stream.h>
#include <libft/stream/stream_buffer.h>
#include <libft/io/fdstream.h>

#include <minitalk/server/output.h>

t_stream	*get_output_stream(void)
{
	static t_stream	output_stream = {.is_valid = false};
	static char		buffer[MTK_SERVER_BUFFER_SIZE];

	if (!output_stream.is_valid)
	{
		output_stream = ft_stream_open_fd(STDOUT_FILENO, STREAM_MODE_O, false);
		ft_stream_use_buffer(
			&output_stream,
			ft_stream_buffer_create_static(buffer, MTK_SERVER_BUFFER_SIZE)
			);
	}
	return (&output_stream);
}
