/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:44:54 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/03/29 19:08:34 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t ldst;
	size_t lsrc;
	size_t var;

	var = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (ldst < size)
		var = size - ldst - 1;
	i = 0;
	while (i < var && src[i])
	{
		dst[i + ldst] = src[i];
		i++;
	}
	dst[i + ldst] = '\0';
	if (size > ldst)
		return (ldst + lsrc);
	else
		return (lsrc + size);
}
