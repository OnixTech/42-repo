/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciano <luciano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:15:49 by luciano           #+#    #+#             */
/*   Updated: 2026/02/16 11:56:45 by luciano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2, size_t s1l, size_t s2l);
void	gnl_strncpy(char *buf, char *str, size_t n);
char	*stash_cleaner(char *stash, char *line, size_t i, size_t *stashlen);
int		read_file(int fd, char **stash, size_t *stashlen);

#endif
