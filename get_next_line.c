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
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_save(fd, stock);
	if (!stock)
		return (NULL);
	line = get_final_line(stock);
	stock = save(stock);
	return (line);
}

char	*read_save(int fd, char *stock)
{
	char	*buf;
	ssize_t	bytes;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = -1;
	while (!ft_strchr(stock, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*get_final_line(char *stock)
{
	ssize_t	i;
	char	*stock2;

	i = 0;
	if (!stock || !stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	stock2 = (char *)malloc(sizeof(char) * (i + 2));
	if (!stock2)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		stock2[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		stock2[i] = stock[i];
		i++;
	}
	stock2[i] = '\0';
	return (stock2);
}

char	*save(char *stock)
{
	size_t	i;
	size_t	j;
	char	*stock2;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	stock2 = (char *)malloc((ft_strlen(stock) - i + 1) * sizeof(char));
	if (!stock2)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		stock2[j++] = stock[i++];
	stock2[j] = '\0';
	free(stock);
	return (stock2);
}
