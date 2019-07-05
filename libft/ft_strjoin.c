/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:50:57 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/05/07 13:13:10 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fresh;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !(fresh = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			fresh[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			fresh[i] = s2[j];
			j++;
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
