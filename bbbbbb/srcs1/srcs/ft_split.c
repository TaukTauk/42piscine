/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:13:55 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/25 10:24:51 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_sep(str[i], charset) == 0 && \
				(ft_is_sep(str[i + 1], charset) == 1 || str[i + 1] == '\0'))
		{
			words++;
		}
		i++;
	}
	return (words);
}

int	word_size(char *str, char *charset, int index)
{
	int	i;

	i = 0;
	while (ft_is_sep(str[index], charset) == 0 && str[i] != '\0')
	{
		index++;
		i++;
	}
	return (i);
}

char	**split_words(char **split, char *str, char *charset, int n)
{
	int	i;
	int	j;
	int	words;
	int	size;

	i = 0;
	words = 0;
	while (str[i] != '\0' && words < n)
	{
		if (ft_is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			size = word_size(str, charset, i);
			split[words] = (char *)malloc(sizeof(char) * (size + 1));
			if (split == NULL)
				return (NULL);
			while (ft_is_sep(str[i], charset) == 0 && str[i] != '\0')
				split[words][j++] = str[i++];
			split[words][j] = '\0';
			words++;
		}
	}
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;

	words = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res = split_words(res, str, charset, words);
	res[words] = 0;
	return (res);
}
