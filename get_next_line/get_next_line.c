/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <lupetill@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:13:48 by luciano           #+#    #+#             */
/*   Updated: 2026/02/04 20:33:54 by lupetill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *gnl_strjoin(char *s1, char *s2, size_t s1l, size_t s2l);
void gnl_strncpy(char *buf, char *str, size_t n);

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*readbuf;
	char	*returnbuf;
	char	flag;
	size_t	n;
	static size_t	stashlen;
	size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbuf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!readbuf)
		return (NULL);
	n = 1;
	flag = 0;
	while (n && !flag)
	{
		i = 0;
		if ((n = read(fd, readbuf, BUFFER_SIZE)) <= 0)
			return (NULL);
		stash = gnl_strjoin(stash, readbuf, stashlen, n);
		stashlen += n;
		while (stash[i] != '\n' && i < stashlen)
			i++;
		if (stash[i] == '\n' && i != stashlen)
			flag = 1;
	}
	printf("\n");
	returnbuf = (char *)malloc(sizeof(char) * (i + 1));
	if (!returnbuf)
		return (NULL);
	printf("%zu, %zu\n", i, stashlen);
	gnl_strncpy(returnbuf, stash, i);
	returnbuf[i + 1] = '\n';
	printf("returnbuf -> %s\n", returnbuf);
	stashlen = 0;
	stash += i + 2;
	printf("stash rest -> %s\n", stash);
	return (returnbuf);
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

	i = 6;
	fd = open("text.txt", O_RDONLY);
	while(i)
	{
		line = get_next_line(fd);
		printf("get_next_line -> %s\n", line);		
		free(line);
		i--;
	}
	printf("\n");
	
	return (0);
}
