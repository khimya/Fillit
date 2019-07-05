/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:38:37 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/05/09 01:38:34 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nextof(char **line, char **s)
{
	int		index;
	char	*copie;

	copie = ft_strdup(*s);
	ft_strdel(&*s);
	index = 0;
	while (copie[index] != '\0' && copie[index] != '\n')
		index++;
	if (copie[index] == '\n')
	{
		*line = ft_strsub(copie, 0, index);
		*s = ft_strdup(copie + index + 1);
		if (*s[0] == '\0')
			ft_strdel(&*s);
	}
	else if (copie[index] == '\0')
	{
		*line = ft_strdup(copie);
	}
	ft_strdel(&copie);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	static char	*s[4096];
	char		*ptr;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > 4096)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		buffer[ret] = '\0';
		ptr = s[fd];
		s[fd] = ft_strjoin(s[fd], buffer);
		ft_strdel(&ptr);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (nextof(&*line, &s[fd]));
}
