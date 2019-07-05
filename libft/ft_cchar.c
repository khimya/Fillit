/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 00:36:56 by ybenbrai          #+#    #+#             */
/*   Updated: 2019/04/13 16:30:12 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cchar(char const *str, char c)
{
	int count_char;

	count_char = 0;
	while (str[count_char] != c)
	{
		count_char++;
	}
	return (count_char);
}
