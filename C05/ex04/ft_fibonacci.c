/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:49:23 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 19:33:53 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	n;

	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	n = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (n);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = ft_fibonacci(1);
	printf("n: %i\n", n);
}
*/
