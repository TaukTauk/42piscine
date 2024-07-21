/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:05:55 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 15:13:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(int grid[4][4], int index, int num)
{
	int	i;

	i = 0;
	while (i++ < index / 4)
	{
		if (grid[i][index % 4] == num)
			return (1);
	}
	i = 0;
	while (i++ < index % 4)
	{
		if (grid[index / 4][i] == num)
			return (1);
	}
	return (0);
}
