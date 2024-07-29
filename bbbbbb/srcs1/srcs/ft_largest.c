/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:48:43 by talin             #+#    #+#             */
/*   Updated: 2024/07/29 17:53:47 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_add(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < a)
		min = b;
	else if (c < b)
		min = c;
	return (min + 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(int *grid, int rows, int cols)
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

int	ft_largest(int grid[10][10])
{
	int	i;
	int	j;
	int	new[10][10];
	int	max;

	i = 0;
	max = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (j == 0 || i == 0)
				new[i][j] = grid[i][j];
			else
				new[i][j] = ft_add(grid[i - 1][j - 1], grid[i][j - 1], grid[i - 1][j]);
			if (new[i][j] > max)
				max = new[i][j];
			j++;
		}
		i++;
	}
	ft_print_grid(new, 10, 10);
	return (max);
}

#include <stdio.h>

int	main(void)
{
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
	int	n = ft_largest(grid);
	printf("n: %i\n", n);
}
