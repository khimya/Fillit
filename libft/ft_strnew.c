/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:36:32 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/04/26 13:47:27 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if ((ptr = (char *)malloc(sizeof(char) * (size + 1))))
	{
		ft_memset(ptr, '\0', size + 1);
		return (ptr);
	}
	else
		return (NULL);
}
