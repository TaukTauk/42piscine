/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:31:19 by talin             #+#    #+#             */
/*   Updated: 2024/07/28 20:55:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_extract_word(char *col, char *le)
{
	char	word[CHUNK_SIZE];
	size_t	i;
	char	*res;
	char	*ptr;

	i = 0;
	ptr = col + 1;
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

void	int_to_str(int number, char *num_str)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = number;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	tmp = number;
	num_str[len] = '\0';
	while (len > 0)
	{
		len--;
		num_str[len] = '0' + (tmp % 10);
		tmp /= 10;
	}
}

char	*get_line_end(char *ls, char *buffer, size_t bsize)
{
	char	*le;

	le = ls;
	while (le < buffer + bsize && *le != '\n')
		le++;
	if (le < buffer + bsize)
		*le = '\0';
	return (le);
}

char	*get_colon_pos(char *ls, char *le)
{
	char	*col;

	col = ls;
	while (col < le && *col != ':')
		col++;
	return (col);
}

int	extract_number(char *ls, char *col)
{
	int		num;
	char	*ptr;

	ptr = ls;
	while (ptr < col)
	{
		if (*ptr >= '0' && *ptr <= '9')
			num = num * 10 + (*ptr - '0');
		ptr++;
	}
	return (num);
}
