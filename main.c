/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:46:39 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/06/24 06:06:52 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	grid_print(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putendl(grid[i++]);
}

int		free_lines(char **lines)
{
	int i;

	i = -1;
	while (++i < 4)
		free(lines[i++]);
	return (-1);
}

void	print_usage(char *str)
{
	if (str == NULL)
		ft_putendl("error");
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(str);
		ft_putendl(" tetris_list_file");
	}
	exit(-1);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_tetris	*lst;

	UNLESS_RET(lst = ft_memalloc(sizeof(t_tetris)), -1);
	if (argc != 2)
		print_usage(argv[0]);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		print_usage(NULL);
	if (!(lst = tetris_read_all(fd)) || tetris_lstlen(lst) > 26)
	{
		tetris_lstdel(lst);
		close(fd);
		print_usage(NULL);
	}
	close(fd);
	solve(lst);
	tetris_lstdel(lst);
	return (0);
}
