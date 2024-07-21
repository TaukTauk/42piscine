/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:16:36 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 20:23:56 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_check_view(int grid[4][4], int index, int input[16]);
int		ft_check(int grid[4][4], int index, int num);
int		*ft_input(char *str);
int		ft_strlen(char *str);
int		ft_solve(int grid[4][4], int input[16], int index);
int		ft_valid(int argc, char **argv);

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

int	main(int argc, char **argv)
{
	int	*input;
	int	grid[4][4];
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			grid[i][j] = 0;
		}
	}
	if (ft_valid(argc, argv) == 1)
		return (0);
	input = ft_input(argv[1]);
	if (ft_solve(grid, input, 0) == 1)
		ft_display(grid);
	else
	{
		ft_putstr("Error\n");
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
				grid[index / 4][index % 4] = 0;
		}
	}
	return (0);
}

int	ft_valid(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (ft_strlen(argv[1]) != 31)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
