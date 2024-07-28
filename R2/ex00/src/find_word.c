/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:03:29 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/28 21:33:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_find_word(int number, char *buffer, size_t bsize)
{
	char	num_str[12];
	char	*ls;
	char	*col;
	char	*le;
	int		num;

	ls = buffer;
	int_to_str(number, num_str);
	while (ls < buffer + bsize)
	{
		le = get_line_end(ls, buffer, bsize);
		col = get_colon_pos(ls, le);
		if (col < le)
		{
			num = extract_number(ls, col);
			if (num == number)
				return (ft_extract_word(col, le));
		}
		ls = le + 1;
	}
	return (0);
}

char	*find_word(int number, const char *filename)
{
	size_t	bsize;
	char	*buffer;
	char	*res;

	buffer = ft_read(filename, &bsize);
	if (buffer == NULL)
		return (0);
	res = ft_find_word(number, buffer, bsize);
	free(buffer);
	return (res);
}
