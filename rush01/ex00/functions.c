/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:55 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 14:54:06 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (n < ft_strlen(str) - 1)
	{
		ft_putchar(str[n]);
		n++;
	}
}

int	ft_atoi(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i++])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + (str[i] + '0');
		}
		else if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == ' ')))
		{
			return (n);
		}
	}
	return (n);
}

void	ft_putnbr(int nb)
{
	int	n;

	if (n < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	else
	{
		n = nb;
	}
	if (n / 10 != 0)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + 48);
}
