/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:17:11 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 18:24:18 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb >= 1)
		result = (nb * ft_recursive_factorial(nb - 1));
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n;

	n = ft_recursive_factorial(5);
	printf("n: %i\n", n);
}
*/
