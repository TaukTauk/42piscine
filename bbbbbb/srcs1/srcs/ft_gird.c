/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gird.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:22:01 by talin             #+#    #+#             */
/*   Updated: 2024/07/29 13:47:45 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define MAX_ROW 100
#define MAX_COL 100
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(char grid[MAX_ROW][MAX_COL], int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_largest(char grid[MAX_ROW][MAX_COL], int rows, int cols)
{
	int	db[MAX_ROW][MAX_COL];
	int	max;
	int	max_i;
	int	max_j;
	int	i;
	int	j;
	int	min_val;

	max = 0;
	max_i = -1;
	max_j = -1;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			db[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (grid[i][j] == '1')
			{
				if (i == 0 || j == 0)
					db[i][j] = 1;
				else
				{
					min_val = db[i - 1][j];
					if (db[i][j - 1] < min_val)
			}
		}
	}
}
