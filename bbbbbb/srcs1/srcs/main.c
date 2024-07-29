/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:57:30 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/29 12:19:29 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

char	*read_file(char *filename);

int	main(int argc, char **argv)
{
	char	**map;
	int	i;

	map = ft_split(read_file(argv[1]), "\n");
	i = 0;
	while (map[i] != 0)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
