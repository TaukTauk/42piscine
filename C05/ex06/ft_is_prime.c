/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:49:43 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 19:55:04 by talin            ###   ########.fr       */
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
/*
#include <stdio.h>

int	main(void)
{
	int	n = ft_is_prime(13);
	printf("n: %i\n", n);
}
*/
