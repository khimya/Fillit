/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:46:22 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/06/24 14:30:53 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"

# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef	struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_tetris
{
	char			letter;
	t_point			point[4];
	t_point			max;
	struct s_tetris	*next;
}				t_tetris;

int				tetris_read(const int fd, t_tetris *tetris);
t_tetris		*tetris_read_all(const int fd);
char			**grid_alloc(int n_rows, int n_cols);
void			grid_print(char **grid, int size);
void			grid_grow(char ***tab, int size);
int				tetris_lstlen(t_tetris *list);
void			solve(t_tetris *t);
int				fillit(t_tetris *list, char **tab, int size, t_point *a);
void			grid_remove_tetris(char **grid, t_tetris *list, t_point *a);
int				has_enough_empty(char **tab, int size, int len);
int				tetris_isvalid(char **line);
t_point			*point_init(t_point *pnt, int x, int y);
void			tetris_lstdel(t_tetris *list);
void			grid_free(char **grid, int size);
void			grid_init(char **grid, int size);
int				free_lines(char **lines);
int				tetris_count_blocks(char **line, int i, int j);
void			print_usage(char *str);
t_point			*tetris_isfit(t_tetris *list, int size, char **tab, t_point *a);
void			grid_add_tetris(char **grid, t_tetris *tetris, t_point *a);
#endif
