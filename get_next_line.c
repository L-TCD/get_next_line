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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_stash(int fd, t_list **stash)
{
	int		read_bytes;
	char	*buf;

	read_bytes = 1;
	while (!found_newline(*stash) && read_bytes != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		read_bytes = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && read_bytes == 0) || read_bytes == -1)
		{
			free(buf);
			return ;
		}
		buf[read_bytes] = '\0';
		add_to_stash(stash, buf, read_bytes);
		free(buf);
	}
}

void	add_to_stash(t_list **stash, char *buf, int read_bytes)
{
	int		i;
	t_list	*l;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (read_bytes + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < read_bytes)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	l = ft_lst_get_last(*stash);
	l->next = new_node;
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*l;
	t_list	*t;
	int		i;
	int		j;

	if (stash != NULL)
		t = malloc(sizeof(t_list));
	if (stash == NULL || t == NULL)
		return ;
	t->next = NULL;
	l = ft_lst_get_last(*stash);
	i = 0;
	while (l->content[i] && l->content[i] != '\n')
		i++;
	if (l->content && l->content[i] == '\n')
		i++;
	t->content = malloc(sizeof(char) * ((ft_strlen(l->content) - i) + 1));
	if (t->content == NULL)
		return ;
	j = 0;
	while (l->content[i])
		t->content[j++] = l->content[i++];
	t->content[j] = '\0';
	free_stash(*stash);
	*stash = t;
}
