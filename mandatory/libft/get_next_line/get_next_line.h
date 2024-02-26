/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:55:08 by anqabbal          #+#    #+#             */
/*   Updated: 2023/12/28 10:09:29 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*my_strchr(const char *s, int c);
char	*my_strjoin(char *s1, char *s2);
void	*my_memcpy(void *dst, const void *src, size_t n);
char	*to_join(char *s1, char *s2, int indice);
void	*my_calloc(size_t count, size_t size);
#endif