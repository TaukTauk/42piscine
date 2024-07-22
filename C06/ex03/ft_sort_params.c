/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:24:00 by talin             #+#    #+#             */
/*   Updated: 2024/07/19 16:17:30 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print(int n, char *str[])
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (str[i][j])
		{
			ft_putchar(str[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				argv[0] = argv[i];
				argv[i] = argv[j];
				argv[j] = argv[0];
			}
			j++;
		}
		i++;
	}
	ft_print(argc, argv);
	return (0);
}
