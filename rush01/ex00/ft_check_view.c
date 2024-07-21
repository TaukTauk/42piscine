/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:17:21 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 20:26:14 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_rrow(int grid[4][4], int index, int input[16])
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (index % 4 == 3)
	{
		while (i >= 0)
		{
			if (grid[index / 4][i] > max)
			{
				max = grid[index / 4][i];
				count++;
			}
			i--;
		}
		if (input[12 + index / 4] != count)
			return (1);
	}
	return (0);
}

int	ft_lrow(int grid[4][4], int index, int input[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (index % 4 == 3)
	{
		while (i < 4)
		{
			if (grid[index / 4][i] > max)
			{
				max = grid[index / 4][i];
				count++;
			}
			i++;
		}
		if (input[8 + index / 4] != count)
			return (1);
	}
	return (0);
}

int	ft_ucol(int grid[4][4], int index, int input[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (index / 4 == 3)
	{
		while (i < 4)
		{
			if (grid[i][index % 4] > max)
			{
				max = grid[i][index % 4];
				count++;
			}
			i++;
		}
		if (input[index % 4] != count)
			return (1);
	}
	return (0);
}

int	ft_dcol(int grid[4][4], int index, int input[16])
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (index / 4 == 3)
	{
		while (i >= 0)
		{
			if (grid[i][index % 4] > max)
			{
				max = grid[i][index % 4];
				count++;
			}
			i--;
		}
		if (input[4 + index % 4] != count)
			return (1);
	}
	return (0);
}

int	ft_check_view(int grid[4][4], int index, int input[16])
{
	if (ft_lrow(grid, index, input) == 1)
		return (1);
	if (ft_rrow(grid, index, input) == 1)
		return (1);
	if (ft_dcol(grid, index, input) == 1)
		return (1);
	if (ft_ucol(grid, index, input) == 1)
		return (1);
	return (0);
}
