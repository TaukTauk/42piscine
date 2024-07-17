/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:51 by talin             #+#    #+#             */
/*   Updated: 2024/07/17 11:11:02 by talin            ###   ########.fr       */
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
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
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

void	ft_print(int nbr, char *base, int n)
{
	if (nbr >= n)
	{
		ft_print((nbr / n), base, n);
		ft_print((nbr % n), base, n);
	}
	else if (nbr < n)
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = ft_strlen(base);
	if (ft_base(base) == 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_print((2147483648 / n), base, n);
			ft_print((2147483648 % n), base, n);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
			ft_print(nbr, base, n);
		}
		else
		{
			ft_print(nbr, base, n);
		}
	}
}
/*
int	main(void)
{
	ft_putnbr_base(100, "01");
	ft_putchar('\n');
	ft_putnbr_base(1235234, "0123456789abcdef");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "01");
}
*/
