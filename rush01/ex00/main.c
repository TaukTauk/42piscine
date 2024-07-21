/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:16:36 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 16:18:26 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_solve(int grid[4][4], int input[16], int index);
void	ft_display(int grid[4][4]);
int	ft_valid(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int	*input;
	int	grid[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	/*if (ft_valid(argc, argv) == 0)
	{
		ft_putstr("Error");
		ft_putchar('\n');
		return (0);
	}*/
	input = ft_input(argv[1]);
	if (ft_solve(grid, input, 0) == 1)
	{
		ft_display(grid);
	}
	else
	{
		ft_putstr("Error1");
		ft_putchar('\n');
	}
	return (0);
}

int	ft_solve(int grid[4][4], int input[16], int index)
{
	int	n;

	if (index == 16)
	{
		return (1);
	}
	n = 0;
	while (++n <= 4)
	{
		if (ft_check(grid, index, n) == 0)
		{
			grid[index / 4][index % 4] = n;
			if (ft_check_view(grid, index, input) == 0)
			{
				if (ft_solve(grid, input, index + 1) == 1)
					return (1);
			}
			else
				grid[index / 4][index % 4] == 0;
		}
	}
	return (0);
}

void	ft_display(int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(grid[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	ft_valid(int argc, char *argv[])
{
	//int	i;

	if (argc != 2)
		return (1);
	/*if (ft_strlen(argv[1]) != 31 || ft_strlen(argv[1]) != 16)
		return (1);
	i = 0;
	while (argv[1][i++])
	{
		if (!(argv[1][i] == ' ' || (argv[1][i] >= '0' && argv[1][i] <= '4') || argv[1][i] == '"'))
			return (1);
	}*/
	return (0);
}
