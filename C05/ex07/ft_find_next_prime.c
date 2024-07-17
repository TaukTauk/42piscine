/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:59:16 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 20:25:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	else
	{
		while (n < nb)
		{
			if ((nb % n) == 0)
			{
				return (0);
			}
			n++;
		}
	}
	return (1);
}
int	ft_find_next_prime(int nb)
{
	int	n;

	n = 0;
	if (nb <= 0)
		return (2);
	while (n <= nb)
	{
		if (ft_is_prime(nb + n) == 1)
		{
			return (nb + n);
		}
		n++;
	}
	return (nb + n);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = ft_find_next_prime(15);
	printf("n: %i\n", n);
}
*/
