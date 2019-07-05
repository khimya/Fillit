/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:47:11 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/06/24 20:12:51 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*tetris_read_all(const int fd)
{
	t_tetris	*list;
	t_tetris	*elem;
	int			ret;
	char		c;

	c = 'A';
	UNLESS_RET(elem = ft_memalloc(sizeof(t_tetris)), NULL);
	list = elem;
	while ((ret = tetris_read(fd, elem)) >= 0)
	{
		elem->letter = c++;
		if (ret == 0)
			return (list);
		UNLESS_DO(elem->next = ft_memalloc(sizeof(t_tetris)),
			tetris_lstdel(list));
		elem = elem->next;
	}
	return (NULL);
}

void		tetris_load(char **line, t_tetris *tetris)
{
	int		i;
	int		j;
	t_point	pnt[2];
	t_point *tmp;

	i = -1;
	j = -1;
	point_init(&pnt[0], 4, 4);
	point_init(&pnt[1], 0, 0);
	while (++i < 16)
		if (line[i / 4][i % 4] == '#')
		{
			tmp = &tetris->point[++j];
			point_init(tmp, i / 4, i % 4);
			point_init(&pnt[0], MIN(pnt[0].x, tmp->x), MIN(pnt[0].y, tmp->y));
		}
	j = -1;
	while (++j < 4)
	{
		tmp = &tetris->point[j];
		point_init(tmp, tmp->x - pnt[0].x, tmp->y - pnt[0].y);
		point_init(&pnt[1], MAX(pnt[1].x, tmp->x), MAX(pnt[1].y, tmp->y));
	}
	point_init(&tetris->max, pnt[1].x, pnt[1].y);
}

int			tetris_read(const int fd, t_tetris *tetris)
{
	int		i;
	char	*line[5];
	int		ret;

	i = -1;
	ft_bzero(line, 5 * sizeof(char *));
	while (++i < 4)
		if (get_next_line(fd, &line[i]) == 0 || ft_strlen(line[i]) != 4)
			return (free_lines(line));
	if ((ret = get_next_line(fd, &line[4])) == 0 || ft_strlen(line[4]) == 0)
	{
		if (tetris_isvalid(line))
			tetris_load(line, tetris);
		else
			return (free_lines(line));
		ret = (ret == 1 && ft_strlen(line[4]) == 0);
		free_lines(line);
		return (ret);
	}
	return (free_lines(line));
}

t_point		*point_init(t_point *pnt, int x, int y)
{
	UNLESS_RET(pnt, NULL);
	pnt->x = x;
	pnt->y = y;
	return (pnt);
}
