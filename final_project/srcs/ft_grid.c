/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:50 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/30 14:51:47 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**ft_grid(char **map)
{
	int	**grid;
	int	h;
	int	l;

	h = 0;
	grid = (int **)malloc(sizeof(int *) * (ft_gridheight(map) - 1));
	if (grid == NULL)
		return (0);
	while (map[h + 1] != 0)
	{
		l = 0;
		grid[h] = (int *)malloc(sizeof(int) * ft_strlen(map[h + 1]));
		while (map[h + 1][l] != '\0')
		{
			if (map[h + 1][l] == ft_find_empty(map[0]))
				grid[h][l] = 1;
			else if (map[h + 1][l] == ft_find_obst(map[0]))
				grid[h][l] = 0;
			l++;
		}
		h++;
	}
	return (grid);
}
