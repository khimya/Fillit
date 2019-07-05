/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:38:50 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/05/07 13:32:24 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 100

int	get_next_line(const int fd, char **line);
int nextof(char **line, char **s);

#endif
