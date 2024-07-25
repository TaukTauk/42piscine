/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:52:13 by talin             #+#    #+#             */
/*   Updated: 2024/07/25 16:26:58 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && ft_check(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
			n++;
		while (str[i] != '\0' && ft_check(str[i], charset) == 0)
			i++;
	}
	return (n);
}

int	ft_size(char *str, char *charset, int index)
{
	int	i;

	i = 0;
	while (str[index] != '\0' && ft_check(str[index], charset) == 0)
	{
		index++;
		i++;
	}
	return (i);
}

char	*ft_sep(char *str, char *charset, int index)
{
	int		len;
	char	*word;

	len = ft_size(str, charset, index);
	word = (char *)malloc(sizeof(char) * (len + 1));
	len += index;
	while (index < len)
	{
		word[index] = str[index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**arr;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_check(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
		{
			arr[j] = ft_sep(str, charset, i);
			j++;
		}
		while (str[i] != '\0' && ft_check(str[i], charset) == 0)
			i++;
	}
	arr[j] = 0;
	return (arr);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	char	**arr;
	int	i;

	(void) ac;
	arr = ft_split(av[1], av[2]);
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

