/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:46:39 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/06/24 20:13:14 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetris_count_blocks(char **line, int i, int j)
{
	int count;

	count = 0;
	ASSERT_DO(i - 1 >= 0 && line[i - 1][j] == '#', count++);
	ASSERT_DO(i + 1 <= 3 && line[i + 1][j] == '#', count++);
	ASSERT_DO(j - 1 >= 0 && line[i][j - 1] == '#', count++);
	ASSERT_DO(j + 1 <= 3 && line[i][j + 1] == '#', count++);
	return (count);
}

int		tetris_isvalid(char **line)
{
	int	i;
	int	n_blocks;
	int	n_edges;
	int n_spaces;

	i = -1;
	n_edges = 0;
	n_blocks = 0;
	n_spaces = 0;
	while (++i < 16)
		if (line[i / 4][i % 4] == '.')
			n_spaces++;
		else if (line[i / 4][i % 4] == '#')
		{
			n_edges += tetris_count_blocks(line, i / 4, i % 4);
			n_blocks++;
		}
		else
			break ;
	return (n_blocks == 4 && n_spaces == 12 && (n_edges == 6 || n_edges == 8));
}

t_point	*tetris_isfit(t_tetris *list, int size, char **tab, t_point *a)
{
	int i;

	if ((list->max.x + a->x) >= size || (list->max.y + a->y) > size)
		return (NULL);
	if ((list->max.y + a->y) == size)
	{
		a->y = 0;
		a->x++;
	}
	i = -1;
	while (++i < 4)
	{
		if (tab[list->point[i].x + a->x][list->point[i].y + a->y] != '.')
		{
			a->y++;
			return (tetris_isfit(list, size, tab, a));
		}
	}
	return (a);
}

int		tetris_lstlen(t_tetris *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	tetris_lstdel(t_tetris *list)
{
	if (list != NULL)
		tetris_lstdel(list->next);
	free(list);
}
