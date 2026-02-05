/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:13:48 by luciano           #+#    #+#             */
/*   Updated: 2026/02/05 11:34:01 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *gnl_strjoin(char *s1, char *s2, size_t s1l, size_t s2l);
void gnl_strncpy(char *buf, char *str, size_t n);
char	*stash_cleaner(char *str, size_t i,  size_t stashlen);

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*buffer;
	char	*line;
	char	flag;
	size_t	n;
	static size_t	stashlen;
	size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	n = 1;
	flag = 0;
	while (n && !flag)
	{
		i = 0;
		if ((n = read(fd, buffer, BUFFER_SIZE)) <= 0)
			return (NULL);
		stash = gnl_strjoin(stash, buffer, stashlen, n);
		stashlen += n;
		while (stash[i] != '\n' && i < stashlen)
			i++;
		if (stash[i] == '\n' && i != stashlen)
			flag = 1;
	}
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	gnl_strncpy(line, stash, i);
	line[i + 1] = '\n';
	stashlen -= (i + 1);
	stash = stash_cleaner(stash, i, stashlen);
	return (line);
}

char	*stash_cleaner(char *str, size_t i,  size_t stashlen)
{
	char	*stash;

	stash = (char *)malloc(sizeof(char) * (stashlen + 1));
	if (!stash)
		return (NULL);
	gnl_strncpy(stash, str + i + 1, stashlen);
	free(str);
	return (stash);
}

char *gnl_strjoin(char *s1, char *s2, size_t s1l, size_t s2l)
{
	char *stash;

	if (!s1)
		s1l = 0;
	stash = (char *)malloc(sizeof(char) * (s1l + s2l));
	if (!stash)
		return (NULL);
	gnl_strncpy(stash, s1, s1l);
	gnl_strncpy(stash + s1l, s2, s2l);
	free(s1);
	return (stash);
}

void gnl_strncpy(char *buf, char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		buf[i] = str[i];
		i++;
	}
}

#include <fcntl.h>
#include <sys/stat.h>
int main (void)
{
	int fd;
	int i;
	char *line;

	i = 26;
	fd = open("text.txt", O_RDONLY);
	while(i)
	{
		line = get_next_line(fd);
		printf("%s\n", line);		
		free(line);
		i--;
	}
	printf("\n");
	
	return (0);
}
