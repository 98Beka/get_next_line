/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:26:50 by ehande            #+#    #+#             */
/*   Updated: 2020/12/13 16:16:34 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rmdr(char *sbf, int i, int j)
{
	char	*buff;

	if (!sbf)
		return (0);
	while (sbf[i] && sbf[i] != '\n')
		i++;
	if (!sbf[i])
	{
		free(sbf);
		return (0);
	}
	while (sbf[j])
		j++;
	if (!(buff = malloc(sizeof(char) * ((j - i) + 1))))
		return (0);
	j = 0;
	i++;
	while (sbf[i])
		buff[j++] = sbf[i++];
	buff[j] = '\0';
	free(sbf);
	return (buff);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s;
	unsigned char *d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!src && !dst)
		return (NULL);
	if (len == 0)
		return (d);
	if (d <= s || d >= (s + len))
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len - 1;
		s += len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	t1;
	size_t	t2;
	size_t	t3;

	t1 = 0;
	t2 = 0;
	if (s2 == NULL)
		return ((char *)s1);
	if (s1)
		while (s1[t1] != '\0')
			t1++;
	while (s2[t2] != '\0')
		t2++;
	if (!(p = (char *)malloc(sizeof(*s1) * (t1 + t2 + 1))))
		return (NULL);
	t3 = t1;
	p[t1 + t2] = '\0';
	while (t1--)
		p[t1] = s1[t1];
	while (t2--)
		p[t3 + t2] = s2[t2];
	free((char *)s1);
	return (p);
}

int		ft_strchr(const char *s, int c)
{
	char *str;

	if (s == NULL)
		return (0);
	str = (char *)s;
	while (c != *str && *str != '\0')
		str++;
	if (*str != c)
		return (0);
	return (1);
}
