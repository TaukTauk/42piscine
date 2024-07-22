/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:25:36 by talin             #+#    #+#             */
/*   Updated: 2024/07/19 14:13:52 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 0)
	{
		while (power >= 1)
		{
			n = n * nb;
			power--;
		}
	}
	return (n);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = ft_iterative_power(7, 2);
	printf("n: %i\n", n);
}
*/
