/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:08:08 by talin             #+#    #+#             */
/*   Updated: 2024/07/20 13:27:37 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
	{
		return (0);
	}
	arr = malloc((max - min) * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*arr;
	int	i;

	i = 0;
	arr = ft_range(1, 19);
	while (i < 18)
	{
		printf("%d, ", arr[i]);
		i++;
	}
}
*/
