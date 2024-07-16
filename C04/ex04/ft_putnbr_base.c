/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:51 by talin             #+#    #+#             */
/*   Updated: 2024/07/16 18:05:55 by talin            ###   ########.fr       */
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
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
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

void	ft_putnbr_base(int nbr, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;
	long	nb;

	nb = nbr;
	if (ft_base(base) == 0)
	{
		return ;
	}
	n = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr_base(nb, base);
	}
	else if (nb >= n)
	{
		ft_putnbr_base((nb / n), base);
		ft_putnbr_base((nb % n), base);
	}
	else if (nb < n)
	{
		ft_putchar(base[nb]);
	}
}

int	main(void)
{
	ft_putnbr_base(100, "01");
}
