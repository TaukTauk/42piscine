/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:16:16 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 14:32:43 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	i;

	if (nb < 0)
		return(0);
	n = 1;
	i = 2;
	while (i <= nb)
	{
		n *= i;
		i++;
	}
	return (n);
}
/*
#include <stdio.h>

int	main(void)
{
	int	x;

	x = ft_iterative_factorial(-5);
	printf("x: %i", x);
}
*/
