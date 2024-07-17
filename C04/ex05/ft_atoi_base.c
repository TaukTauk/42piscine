/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:30:23 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 12:00:38 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

int	ft_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || \
				(str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	i;

	i = 0;
	n = ft_strlen(base);
	if (ft_base(base) == 1)
	{
		while (str[i])
		{
		}
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	x;

	x = ft_strlen("hello");
	printf("x: %i\n", x);
}
*/
