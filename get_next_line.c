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
	static t_list	*stash = NULL;
	char			*line;

	printf("BUFFER_SIZE=%d\nfd=%d\n", BUFFER_SIZE, fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	//1. read fd => linked list
	// read_and_stash(fd, &stash);
	//2. stash => line
	//3. clean up stash

	return ("ok");
}

// void	read_and_stash(int fd, t_list **stash)
// {
// 	int	read_bytes;
// 	char	*buf;

// 	read_bytes = 1;
// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)).
// 	if (buf == NULL)
// 		return ;
// 	while ()
// 	{
// 		read_bytes = read(fd, buf, BUFFER_SIZE);
// 		buf[read_bytes] = '\0';
// 	}
// }
