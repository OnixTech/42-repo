/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:13:48 by luciano           #+#    #+#             */
/*   Updated: 2026/02/10 11:40:49 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;
	static size_t	stashlen;
	size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		stash_null(&stash, &stashlen);
		return (NULL);
	}
	if (!read_file(fd, &stash, &stashlen, BUFFER_SIZE))
		return (NULL);
	if (!stash || stashlen == 0)
		return (NULL);
	i = has_nl(stash, stashlen, 0);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	gnl_strncpy(line, stash, i);
	stash = stash_cleaner(stash, line, i, &stashlen);
	if (!stash && stashlen != 0)
		return (NULL);
	return (line);
}

// #include <fcntl.h>
// #include <sys/stat.h>
// #include <stdio.h>

// int main (int arg, char **argc)
// {
// 	int fd;
// 	char *line;

// 	fd = open(argc[1], O_RDONLY);
//   (void)arg;
// 	if (fd < 0)
// 		return (1);
// 	while((line = get_next_line(fd)) != NULL)
// 		free(line);
// 	close(fd);
// 	return (0);
// }
