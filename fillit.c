/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:46:10 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/06/24 06:00:33 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		grid_init(char **grid, int size)
{
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			grid[i][j++] = '.';
		grid[i++][j] = '\0';
	}
}

void		grid_free(char **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(grid[i++]);
	free(grid);
}

int			fillit(t_tetris *list, char **tab, int size, t_point *origin)
{
	t_point	a;

	point_init(&a, 0, 0);
	if (list == NULL)
	{
		grid_print(tab, size);
		exit(1);
	}
	if (!has_enough_empty(tab, size, tetris_lstlen(list)))
		return (0);
	if ((origin = tetris_isfit(list, size, tab, origin)) != NULL)
	{
		grid_add_tetris(tab, list, origin);
		if (fillit(list->next, tab, size, &a) == 0)
		{
			grid_remove_tetris(tab, list, origin);
			origin->y++;
			if (!fillit(list, tab, size, origin))
				return (0);
		}
	}
	return (0);
}

void		solve(t_tetris *list)
{
	int		size;
	char	**grid;
	t_point	origin;

	point_init(&origin, 0, 0);
	size = ft_sqrt(tetris_lstlen(list) * 4);
	grid = grid_alloc(size, size);
	grid_init(grid, size);
	while (fillit(list, grid, size++, &origin) == 0)
	{
		grid_init(grid, size - 1);
		point_init(&origin, 0, 0);
		grid_grow(&grid, size);
	}
	grid_free(grid, size);
	tetris_lstdel(list);
}
