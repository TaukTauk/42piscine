/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:14:50 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/29 15:25:56 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

int	ft_gridheight(char **grid);

char	ft_find_empty(char *str);

char	ft_find_obst(char *str);

void	print_grid(int **grid, int l, int h)
{
	int	i;
	int	n;
	
	i = 0;
	while (i < h)
	{
		n = 0;
		while (n < l)
		{
			printf("%d, ", grid[i][n]);
			n++;
		}
		printf("\n");
		i++;
	}
}

int	**ft_grid(char **str)
{
	int	**grid;
	int	h;
	int	l;

	h = 0;
	grid = (int **)malloc(sizeof(int *) * (ft_gridheight(str) - 1));
	if (grid == NULL)
		return (0);
	while (str[h + 1] != 0)
	{
		l = 0;
		grid[h] = (int *)malloc(sizeof(int) * ft_strlen(str[h + 1]));
		while (str[h + 1][l] != '\0')
		{
			if (str[h + 1][l] == ft_find_empty(str[0]))
				grid[h][l] = 1;
			else if (str[h + 1][l] == ft_find_obst(str[0]))
				grid[h][l] = 0;
			l++;
		}
		h++;
	}
	print_grid(grid, l, h);
	return (grid);
}
