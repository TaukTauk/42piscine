/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:02:24 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/30 13:47:26 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_verchar(char *str)
{
	int	l;
	int	i;

	l = ft_strlen(str);
	i = 3;
	if (str[l - 3] == str [l - 2] || str[l - 3] == str[l - 1] || \
			str[l - 2] == str [l - 1] || l < 4)
		return (0);
	while (i > 0)
	{
		if (str[l - i] < 32 || str[l - i] > 126)
			return (0);
		i--;
	}
	return (1);
}

int	ft_valid(char **map)
{
	int	a;
	int	b;

	if (ft_gridheight(map) < 2 || ft_strlen(map[1]) < 1 || \
		ft_verchar(map[0]) == 0 || \
		(ft_gridheight(map) - 1) != ft_lineno(map[0]))
		return (0);
	a = 0 ;
	while (map[++a] != 0)
	{
		if (map[a + 1] != 0)
		{
			if (ft_strlen(map[a]) != ft_strlen(map[a + 1]))
				return (0);
		}
		b = 0;
		while (map[a][b] != '\0')
		{
			if (map[a][b] != ft_find_empty(map[0]) && \
					map[a][b] != ft_find_obst(map[0]))
				return (0);
			b++;
		}
	}
	return (1);
}
