/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:27:02 by ehande            #+#    #+#             */
/*   Updated: 2020/12/10 09:25:13 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int         get_next_line(int fd, char **line);
void		*ft_memmove(void *dst, const void *src, size_t len);
int		    ft_strchr(const char *s, int c);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    *rmdr(char *sbf, int i, int j);
#endif
