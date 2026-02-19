/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:13:48 by luciano           #+#    #+#             */
/*   Updated: 2026/02/16 11:52:05 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	stash_null(int fd, char **stash, size_t *stashlen)
{
	if (read(fd, 0, 0) < 0)
	{
		free(*stash);
		*stash = NULL;
		*stashlen = 0;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	static size_t	stashlen;
	size_t			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash_null(fd, &stash, &stashlen))
		return (NULL);
	read_file(fd, &stash, &stashlen);
	if (!stash || stashlen == 0)
		return (NULL);
	i = 0;
	while (i < stashlen)
		if (stash[i++] == '\n')
			break ;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	gnl_strncpy(line, stash, i);
	stash = stash_cleaner(stash, line, i, &stashlen);
	if (!stash && stashlen != 0)
		return (NULL);
	return (line);
}
/*
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main (int arg, char **argc)
{
	int fd;
	char *line;

	fd = open(argc[1], O_RDONLY);
  (void)arg;
	if (fd < 0)
		return (1);
	while((line = get_next_line(fd)) != NULL)
		free(line);
	close(fd);
	return (0);
}*/
