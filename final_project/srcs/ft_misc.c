/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:15:47 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/30 11:47:42 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_gridheight(char **grid)
{
	int	i;

	i = 0;
	while (grid[i] != 0)
		i++;
	return (i);
}

int	ft_lineno(char *str)
{
	int	i;
	int	nb;
	int	a;

	i = 0;
	nb = 0;
	while (str[i + 3] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			a = str[i] - '0';
			nb = (nb * 10) + a;
		}
		i++;
	}
	return (nb);
}
