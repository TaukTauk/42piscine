/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:43:24 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 18:48:46 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	n;

	n = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power > 0)
		n = nb * ft_recursive_power(nb, power - 1);
	return (n);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = ft_recursive_power(7, 2);
	printf("n: %i\n", n);
}
*/
