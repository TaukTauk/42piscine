/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:49:29 by talin             #+#    #+#             */
/*   Updated: 2024/07/28 20:22:25 by ubuntu           ###   ########.fr       */
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

	int_to_str(number, num_str);
	while (ls < buffer + bsize)
	{
		le = get_line_end(ls, buffer, bsize);
		col = get_colon_pos(ls, le);
		if (col < le)
		{
			num = extract_number(ls, col);
			if (num == number)
				return (ft_extract_word(ls, col, le));
		}
		ls = le + 1;
	}
	return (0);
}
