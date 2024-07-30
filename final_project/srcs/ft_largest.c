/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:48:43 by talin             #+#    #+#             */
/*   Updated: 2024/07/30 15:13:50 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_add(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < a)
		min = b;
	if (c < min)
		min = c;
	return (min + 1);
}

void	ft_do(int **grid, int i, int j)
{
	if (grid[i][j] == 0)
		grid[i][j] = 0;
	else if (j == 0 || i == 0)
		grid[i][j] = grid[i][j];
	else
		grid[i][j] = ft_add(grid[i - 1][j - 1], \
				grid[i][j - 1], grid[i - 1][j]);
}

struct t_grid	ft_largest(int **grid, char **map)
{
	int				i;
	int				j;
	struct t_grid	res;

	i = -1;
	res.max = 0;
	while (++i < ft_gridheight(map) - 1)
	{
		j = -1;
		while (++j < ft_strlen(map[1]))
		{
			ft_do(grid, i, j);
			if (grid[i][j] > res.max)
			{
				res.max = grid[i][j];
				res.x = i;
				res.y = j;
			}
		}
	}
	i = -1;
	while (++i < ft_gridheight(map) - 1)
		free(grid[i]);
	free(grid);
	return (res);
}
