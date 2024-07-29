/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:57:30 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/29 15:07:51 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

char	*read_file(char *filename);

int	**ft_grid(char **str);

char	ft_find_empty(char *str);

char	ft_find_obst(char *str);

char	ft_find_full(char *str);

int	main(int argc, char **argv)
{
	char	**map;
	int	i;
	int	**grid;

	map = ft_split(read_file(argv[1]), "\n");
	i = 0;
	while (map[i] != 0)
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("Empty: %c\nObstacle: %c\nFull: %c\n", ft_find_empty(map[0]), ft_find_obst(map[0]), ft_find_full(map[0]));
	grid = ft_grid(map);
	return (0);
}
