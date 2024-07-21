/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:55:16 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 19:39:45 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str);
int		ft_atoi(char *str);

int	*ft_input(char *str)
{
	int	i;
	int	j;
	int	*grid;

	grid = malloc(sizeof(int) * 16);
	if (grid == NULL)
	{
		ft_putstr("Malloc\n");
		return (0);
	}
	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			grid[j++] = ft_atoi(str + i);
		}
	}
	return (grid);
}
