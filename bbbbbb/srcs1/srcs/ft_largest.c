/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:48:43 by talin             #+#    #+#             */
/*   Updated: 2024/07/29 20:54:53 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(int **grid, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (grid[i][j] > 9)
				ft_putchar(grid[i][j] / 10 + '0');
			ft_putchar(grid[i][j] % 10 + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_largest(int **grid, int rows, int cols)
{
	int	i;
	int	j;
	int	max;
	int	max_i;
	int	max_j;

	i = 0;
	max = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (grid[i][j] == 0)
				grid[i][j] = 0;
			else if (j == 0 || i == 0)
				grid[i][j] = grid[i][j];
			else
				grid[i][j] = ft_add(grid[i - 1][j - 1], grid[i][j - 1], grid[i - 1][j]);
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}
	ft_print_grid(grid, 10, 10);
	return (max);
}

#include <stdio.h>

int	main(void)
{
	int	max_i;
	int	max_j;
	int	grid[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	int	n = ft_largest(grid, 10, 10);
	printf("n: %i\n", n);
	//printf("Index of the largest element: (%i, %i)\n", max_i, max_j);
}
