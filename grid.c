/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:47:03 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/06/24 06:05:20 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	grid_add_tetris(char **grid, t_tetris *tetris, t_point *a)
{
	int		i;
	t_point *tmp;

	i = 0;
	while (i < 4)
	{
		tmp = &tetris->point[i++];
		grid[tmp->x + a->x][tmp->y + a->y] = tetris->letter;
	}
}

char	**grid_alloc(int n_rows, int n_cols)
{
	char	**tab;
	int		i;

	i = 0;
	UNLESS_DO(tab = (char **)malloc(sizeof(char *) * (n_rows + 1)), NULL);
	while (i < n_rows + 1)
		if (!(tab[i++] = (char*)malloc(n_cols * sizeof(char))))
			while (i - 2 >= 0)
				free(tab[i--]);
	return (tab);
}

void	grid_remove_tetris(char **grid, t_tetris *list, t_point *a)
{
	int		i;
	t_point	*tmp;

	i = 0;
	while (i < 4)
	{
		tmp = &list->point[i++];
		grid[tmp->x + a->x][tmp->y + a->y] = '.';
	}
}

void	grid_grow(char ***grid, int size)
{
	grid_free(*grid, size);
	*grid = grid_alloc(size + 1, size);
	grid_init(*grid, size);
}

int		has_enough_empty(char **grid, int size, int n_tetris)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			if (grid[i][j++] == '.')
				count++;
		i++;
	}
	if (count < (n_tetris * 4))
		return (0);
	return (1);
}
