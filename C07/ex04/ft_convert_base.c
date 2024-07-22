/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:56:33 by talin             #+#    #+#             */
/*   Updated: 2024/07/22 12:33:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n))
		n++;
	return (n);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (sign % 2 == 1)
		return (n * -1);
	return (n);
}

int	ft_base(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+' || \
				str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
/*
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
}
*/

#include <stdio.h>

int	main(int ac, char **av)
{
	printf("N: %i\n", ft_base(av[1]));
}

