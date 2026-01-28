/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:13:48 by luciano           #+#    #+#             */
/*   Updated: 2026/01/29 00:42:28 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*buf;
	static char	c;
	size_t	i;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buf = (char *)malloc(sizeof(void) * (BUFFER_SIZE));
	if (!buff)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) && i < (BUFFER_SIZE - 1) && c != '\n')
		buf[i++] = c;
	buf[i] = '\n';
	while (c != '\n')
		read(fd, &c, 1);
	return (buf);
}

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
int main (void)
{
	int fd;
	int i;
	char *line;

	i = 5;
	fd = open("text.txt", O_RDONLY);
	while(i--)
	{
		line = get_next_line(fd);
		printf("%s", line);		
		free(line);
	}
	return (0);
}
