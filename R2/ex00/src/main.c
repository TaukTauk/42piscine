/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:03:01 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/28 21:29:00 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int		number;
	char	*word;

	if (ac == 2)
	{
		number = ft_atoi(av[1]);
		word = find_word(number, "numbers.dict");
		if (word != NULL)
		{
			ft_putstr(word);
			write(1, "\n", 1);
			free(word);
		}
		else
			ft_putstr("Error\n");
	}
	else if (ac == 3)
	{
		ft_putstr("Sorry, this request cannot be proceeded today. :(\n");
	}
	else
		ft_putstr("Usage: ./rush-02 20\nUsage: ./rush-02 20 \"hello\"\n");
	return (0);
}
