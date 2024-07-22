/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:06:51 by talin             #+#    #+#             */
/*   Updated: 2024/07/22 15:56:23 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

int	ft_size(int size, char **strs, char *sep)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < size)
	{
		n += ft_strlen(strs[i]);
		i++;
	}
	n += (size * ft_strlen(sep));
	return (n);
}

void	ft_print(int size, char **strs, char *sep, char *ptr)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
		{
			ptr[k] = strs[i][j];
			k++;
		}
		j = -1;
		if (i < size - 1)
		{
			while (sep[++j])
			{
				ptr[k] = sep[j];
				k++;
			}
		}
	}
	ptr[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		n;
	char	*ptr;

	n = ft_size(size, strs, sep);
	ptr = malloc(n * sizeof(char));
	if (!ptr)
		return (0);
	ft_print(size, strs, sep, ptr);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*a[3];
	char	*sep = "world ";
	int	size = 3;

	a[0] = "hello ";
	a[1] = "hello1 ";
	a[2] = "hello2 ";
	printf("%s\n", ft_strjoin(size, a, sep));
}
*/
