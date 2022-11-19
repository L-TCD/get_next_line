/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoissar <lcoissar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:17:20 by lcoissar          #+#    #+#             */
/*   Updated: 2022/11/19 10:17:20 by lcoissar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char *save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("BUFFER_SIZE=%d\nfd=%d\n", BUFFER_SIZE, fd);
	return ("ok");
}
