/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:57:30 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/30 15:48:05 by hsoe             ###   ########.fr       */
/*   Updated: 2024/07/30 11:45:28 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_bigsqre(char *str)
{
	char	**map;
	char	*content;
	int		i;

	content = read_file(str);
	map = ft_split(content, "\n");
	free(content);
	if (ft_valid(map) == 0)
	{
		ft_putstr("map error\n");
	}
	else
	{
		ft_fill(map, ft_largest(ft_grid(map), map));
		ft_print_map(map, ft_gridheight(map), ft_strlen(map[1]));
	}
	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			ft_bigsqre(argv[i]);
			i++;
		}
	}
	return (0);
}
