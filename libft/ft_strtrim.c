/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:33:50 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/04/02 11:49:40 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	int		h;
	int		i;
	int		z;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	z = ft_strlen(s) - 1;
	while ((s[z] == ' ' || s[z] == '\n' || s[z] == '\t') && z >= 0)
		z--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (z <= i)
		return (ft_strdup(""));
	if (!(trimmed = (char *)malloc(sizeof(char) * (z - i + 2))))
		return (NULL);
	h = z - i;
	while (j <= h)
		trimmed[j++] = s[i++];
	trimmed[j] = '\0';
	return (trimmed);
}
