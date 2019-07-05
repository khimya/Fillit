/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:05:57 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/03/29 10:06:36 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (src[i])
			dest[i] = src[i];
		else
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
			j = 1;
		}
		if (j == 1)
			break ;
		i++;
	}
	return (dest);
}
