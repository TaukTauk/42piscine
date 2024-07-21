/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:55:16 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 17:17:20 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(char *str);

int	*ft_input(char *str)
{
	int	i;
	int	j;
	int	*grid;

	grid = malloc(16 * sizeof(int));
	if (!grid)
		return (0);
	i = 0;
	j = 0;
	while (str[i++])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			grid[j++] = ft_atoi((str + i));
		}
	}
	return (grid);
}
