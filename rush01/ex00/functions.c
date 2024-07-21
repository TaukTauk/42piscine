/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:57:55 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 19:48:53 by ubuntu           ###   ########.fr       */
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
	while (n < ft_strlen(str))
	{
		ft_putchar(str[n]);
		n++;
	}
}

int	ft_atoi(char *str)
{
	int	n;
	int	i;
	int	sign;

	n = 0;
	i = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
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

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
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
