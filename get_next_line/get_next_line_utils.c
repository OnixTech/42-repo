/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:38:33 by luciano           #+#    #+#             */
/*   Updated: 2026/02/11 21:20:38 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2, size_t s1l, size_t s2l)
{
	char	*stash;

	if (!s1)
		s1l = 0;
	stash = malloc(s1l + s2l + 1);
	if (!stash)
		return (NULL);
	if (s1l > 0)
		gnl_strncpy(stash, s1, s1l);
	gnl_strncpy(stash + s1l, s2, s2l);
	free(s1);
	return (stash);
}

void	gnl_strncpy(char *buf, char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
}

char	*stash_cleaner(char *stash, char *line, size_t i, size_t *stashlen)
{
	char	*tmp;

	*stashlen -= i;
	if (*stashlen == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	i--;
	tmp = malloc(*stashlen + 1);
	if (!tmp)
		return (NULL);
	gnl_strncpy(tmp, stash + i + 1, *stashlen);
	free(stash);
	if (!tmp)
	{
		free(line);
		free(stash);
		stash = NULL;
		*stashlen = 0;
	}
	return (tmp);
}

// int	has_nl(char *s, size_t len, char flag)
// {
// 	size_t	i;

// 	i = 0;
// 	if (flag)
// 	{
// 		while (i < len)
// 			if (s[i++] == '\n')
// 				return (i);
// 		return (0);
// 	}
// 	else
// 	{
// 		while (i < len)
// 			if (s[i++] == '\n')
// 				break ;
// 		return (i);
// 	}
// }

int	set_buf(int fd, ssize_t *n, char *buf, size_t bs)
{
	*n = read(fd, buf, bs);
	if (*n < 0)
	{
		free(buf);
		return (-1);
	}
	buf[*n] = '\0';
	return (1);
}

int	read_file(int fd, char **stash, size_t *stashlen, size_t bs)
{
	ssize_t	n;
	char	*buf;
	size_t	i;

	buf = malloc(bs + 1);
	if (!buf)
		return (0);
	n = 1;
	while (n > 0)
	{
		i = 0;
		if (!set_buf(fd, &n, buf, bs))
			return (0);
		if (n == 0)
			break ;
		*stash = gnl_strjoin(*stash, buf, *stashlen, (size_t)n);
		if (!*stash)
			return (0);
		*stashlen += (size_t)n;
		while (i < *stashlen)
			if ((*stash)[i++] == '\n')
				n = 0;
	}
	free(buf);
	return (1);
}
