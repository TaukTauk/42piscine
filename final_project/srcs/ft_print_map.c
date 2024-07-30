/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:42 by talin             #+#    #+#             */
/*   Updated: 2024/07/30 13:48:38 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_map(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 1;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_fill(char **map, struct t_grid res)
{
	int	i;
	int	j;

	i = 1;
	while (i <= res.x + 1)
	{
		j = 0;
		while (j <= res.y)
		{
			if ((i >= (res.x - res.max + 2) && i <= res.x + 1) && \
				(j >= (res.y - res.max + 1) && j <= res.y))
			{
				if (map[i][j] == ft_find_empty(map[0]))
					map[i][j] = ft_find_full(map[0]);
			}
			j++;
		}
		i++;
	}
}
