/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:43:26 by talin             #+#    #+#             */
/*   Updated: 2024/07/23 11:53:13 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc((max - min) * sizeof(int))
	if (!arr)
		*range = NULL;
		return (0);
	}
	*range = arr;
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	int	*arr;
	i = 0;
	int	n = ft_ultimate_range(&arr, 0, 1);
	while (i < 18)
	{
		printf("%i, ", arr[i]);
		i++;
	}
	printf("\nn: %i\n", n);
}
*/
