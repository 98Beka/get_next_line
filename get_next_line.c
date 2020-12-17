/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:26:30 by ehande            #+#    #+#             */
/*   Updated: 2020/12/13 16:03:12 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		outbf(char **line, char *str)
{
	int		i;
	char	*bf;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(bf = malloc(sizeof(char) * (i + 1))))
		return (0);
	bf[i] = '\0';
	while (i--)
		bf[i] = str[i];
	*line = bf;
	return (1);
}

int rd_file(int ri, int fd, char *buff, char **sbf)
{
	if ((ri = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ri] = '\0';
		*sbf = ft_strjoin(*sbf, buff);
		return(ri);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*sbf;
	int				ri;

	ri = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(sbf, '\n') && ri != 0)
		if((ri = rd_file(ri, fd, buff, &sbf))== -1)
			return(-1);
	free(buff);
	if (!outbf(line, sbf))
		return (-1);
	sbf = rmdr(sbf, 0, 0);
	if (ri == 0)
		return (0);
	return (1);
}
