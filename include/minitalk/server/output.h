/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:40:10 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/09 15:12:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include <libft/stream/stream.h>

# ifndef MTK_SERVER_BUFFER_SIZE
#  define MTK_SERVER_BUFFER_SIZE 1024
# endif

t_stream
*get_output_stream(void);

#endif
