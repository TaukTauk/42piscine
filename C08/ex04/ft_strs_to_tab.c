/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:33:18 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/22 21:18:08 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*#include "ft_stock_str.h"*/

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
}

#include <stdio.h>

int	main(void)
{
	char	*dest;

	printf("Dest: %s\n", ft_strcpy(dest, "hello"));
}
