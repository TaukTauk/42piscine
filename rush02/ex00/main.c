/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin  <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:55:46 by talin             #+#    #+#             */
/*   Updated: 2024/07/28 20:07:03 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*find_word(int number, const char *filename)
{
	size_t	bsize;
	char	*buffer;
	char	*res;

	buffer = ft_read(filename, &bsize);
	if (buffer == NULL)
		return (0);
	res = find_word(number, buffer, bsize);
	free(buffer);
	return (res);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

int	main(int ac, char **av)
{
	int		number;
	char	*word;

	number = ft_atoi(av[1]);
	if (ac == 2)
	{
		word = find_word(number, "numbers.dict");
		if (word != NULL)
		{
			ft_putstr(word);
			free(word);
		}
		else
			ft_putstr("Error\n");
	}
	if (ac == 3)
		ft_putstr("Sorry, this function does not work today. :(");
	return (0);
}
