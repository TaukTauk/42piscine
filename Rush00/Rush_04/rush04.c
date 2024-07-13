/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:45:29 by talin             #+#    #+#             */
/*   Updated: 2024/07/13 12:09:55 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	condition_rush(int i, int j, int y, int x);

void	row_col(int i, int j, int y, int x);

char	rush(int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (x == 1 || y == 1)
			{
				row_col(i, j, y, x);
			}
			else
			{
				condition_rush(i, j, y, x);
			}
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	condition_rush(int i, int j, int y, int x)
{
	if ((i == 0 && j == 0) || (i == (x - 1) && j == (y - 1)))
	{
		ft_putchar('A');
	}
	else if ((i == (x - 1) && j == 0) || (i == 0 && j == (y - 1)))
	{
		ft_putchar('C');
	}
	else if (((i == 0 || i == (x - 1)) && j != 0 && j != (y - 1)) \
			|| ((j == 0 || j == (y - 1)) && i != 0 && i != (x - 1)))
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	row_col(int i, int j, int y, int x)
{
	if (x == 1)
	{
		if (i == 0 && j == (y - 1))
		{
			ft_putchar('C');
		}
		else
		{
			condition_rush(i, j, y, x);
		}
	}
	else if (y == 1)
	{
		if (j == 0 && i == (x - 1))
		{
			ft_putchar('C');
		}
		else
		{
			condition_rush(i, j, y, x);
		}
	}
}
