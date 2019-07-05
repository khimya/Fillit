/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:40:57 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/02/27 11:46:29 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*troncon;
	unsigned int	i;

	i = 0;
	if (!s || !(troncon = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		troncon[i] = s[i + start];
		i++;
	}
	troncon[i] = '\0';
	return (troncon);
}
