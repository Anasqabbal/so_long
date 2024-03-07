/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:19:59 by anqabbal          #+#    #+#             */
/*   Updated: 2023/12/28 10:10:27 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
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