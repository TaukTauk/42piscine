/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:07:01 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/15 17:45:46 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = ft_strlen(to_find);
	if (x == 0)
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		while (to_find[j] == str[i + j])
		{
			if (j == x - 1)
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "hello world!";
	char	to_find[] = "el";
	char	nth[] = "at";
	char	*p;
	char	*q;

	p = ft_strstr(str, to_find);
	q = ft_strstr(str, nth);
	printf("p: %s", p);
	printf("q: %s", q);
}

