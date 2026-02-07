/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:38:33 by luciano           #+#    #+#             */
/*   Updated: 2026/02/07 14:53:05 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// »»-----► Number of lines: 13
char *gnl_strjoin(char *s1, char *s2, size_t s1l, size_t s2l)
{
	char *stash;

	if (!s1)
		s1l = 0;
	stash = (char *)malloc(sizeof(char) * (s1l + s2l + 1));
	if (!stash)
		return (NULL);
	if (s1l > 0)
		gnl_strncpy(stash, s1, s1l);
	gnl_strncpy(stash + s1l, s2, s2l);
	stash[s1l + s2l] = '\0';
	free(s1);
	return (stash);
}
// »»-----► Number of lines: 8
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
// »»-----► Number of lines: 9
char	*stash_cleaner(char *str, size_t i,  size_t stashlen)
{
	char	*stash;

	stash = (char *)malloc(sizeof(char) * (stashlen + 1));
	if (!stash)
		return (NULL);
  gnl_strncpy(stash, str + i + 1, stashlen);
	stash[stashlen] = '\0';
	free(str);
	return (stash);
}
// »»-----► Number of lines: 36
int  read_file(int fd, char **stash, size_t *stashlen, size_t buffer_size)
{
	ssize_t	n;
	size_t	i;
	char	*buffer;
	char	flag;

	buffer = (char *)malloc(sizeof(char) * (buffer_size + 1));
	if (!buffer)
		return (0);
	n = 1;
	flag = 0;
	while (n > 0 && !flag)
	{
		i = 0;
		n = read(fd, buffer, buffer_size);
		if (n < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[n] = '\0';
		if (n == 0)
			break;
		*stash = gnl_strjoin(*stash, buffer, *stashlen, (size_t)n);
		if (!(*stash))
		{
			free(buffer);
			return (0);
		}
		*stashlen += (size_t)n;
		while (i < *stashlen && (*stash)[i] != '\n')
			i++;
		if (i < *stashlen && (*stash)[i] == '\n')
			flag = 1;
	}
	free(buffer);
  return (1);
}
