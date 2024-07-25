/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:33:18 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/25 15:25:51 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int					index;

	arr = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!arr)
	{
		return (NULL);
	}
	index = 0;
	while (index < ac)
	{
		arr[index].size = ft_strlen(av[index]);
		arr[index].str = av[index];
		arr[index].copy = ft_strcpy(arr[index].copy, av[index]);
		index++;
	}
	arr[index].str = 0;
	arr[index].copy = 0;
	return (arr);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	struct s_stock_str	*arr;
	int	i;

	arr = ft_strs_to_tab(ac, av);
	i = 0;
	while (i < ac)
	{
		printf("index %d\n", i);
		printf("Size: %i\n", arr[i].size);
		printf("Str: %s\n", arr[i].str);
		printf("Copy: %s\n", arr[i].copy);
		i++;
	}
	free(arr->copy);
	free(arr);
}
*/
