/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:31:19 by talin             #+#    #+#             */
/*   Updated: 2024/07/28 17:52:23 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_extract(char *ls, char *col, char *le)
{
	char	word[CHUNK_SIZE];
	size_t	i;
	char	*res;
	char	*ptr;

	i = 0;
	*ptr = col + 1;
	while (ptr < le)
	{
		if (*ptr != ' ' && *ptr != '\t')
			word[i++] = *ptr;
		ptr++;
	}
	word[i] = '\0';
	res = ft_alloc(i + 1);
	if (res != NULL)
	{
		ft_strncpy(res, word, i);
		res[i] = '\0';
	}
	return (res);
}

int	ft_num_len(int number)
{
	int	i;

	i = 0;
	while (number > 0)
	{
		number /= 10;
		i++;
	}

}
