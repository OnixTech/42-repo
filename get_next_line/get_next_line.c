/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:13:48 by luciano           #+#    #+#             */
/*   Updated: 2026/02/08 21:13:54 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// »»-----► Number of lines: 54
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
      free(stash);
      stash = NULL;
      stashlen = 0;
      return (NULL);
  }
  if (!read_file(fd, &stash, &stashlen, BUFFER_SIZE))
  {
      free(stash);
      stash = NULL;
      stashlen = 0;
      return (NULL);
  }
  if (!stash || stashlen == 0)
      return (NULL);
  i = 0;
	while (i < stashlen && stash[i] != '\n')
		i++;
	if (i < stashlen && stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	gnl_strncpy(line, stash, i);
	line[i] = '\0';
	stashlen -= i;
if (stashlen == 0)
{
    free(stash);
    stash = NULL;
    return (line);
}
{
    char *tmp = stash_cleaner(stash, i - 1, stashlen);
    if (!tmp)
    {
        free(line);
        free(stash);
        stash = NULL;
        stashlen = 0;
        return (NULL);
    }
    stash = tmp;
}
return (line);
}

// #include <fcntl.h>
// #include <sys/stat.h>
// #include <stdio.h>
// // »»-----► Number of lines: 11
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
