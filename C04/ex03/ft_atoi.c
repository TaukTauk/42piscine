/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:14:36 by talin             #+#    #+#             */
/*   Updated: 2024/07/16 16:12:10 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || \
			c == '\v' || c == '\n' || c == '\f')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	ft_num(char c)
{
	if (ft_isspace(c) == 0 || (c >= '0' && c <= '9') || (c == '-' || c == '+'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	ft_minus(char *str)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			n = n * (-1);
		}
		i++;
	}
	return (n);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (((ft_isspace(str[i]) == 0) || (ft_num(str[i]) == 0)) \
				&& (str[i] >= '0' && str[i] <= '9'))
		{
			n = n * 10 + (str[i] - '0');
		}
		else if ((((str[i - 1] >= '0' && str[i - 1] <= '9') && \
						ft_isspace(str[i]) == 0)) || ft_num(str[i]) == 1)
		{
			return (n * ft_minus(str));
		}
		i++;
	}
	return (n * ft_minus(str));
}
/*
#include <stdio.h>

int	main(void)
{
	char a[] = "  ---++--123   456";
	printf("N: %i\n", ft_minus(a));
	printf("A: %i\n", ft_atoi(a));
}
*/
