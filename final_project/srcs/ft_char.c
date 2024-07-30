/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:52:18 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/30 14:27:20 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_find_empty(char *str)
{
	return (str[ft_strlen(str) - 3]);
}

char	ft_find_obst(char *str)
{
	return (str[ft_strlen(str) - 2]);
}

char	ft_find_full(char *str)
{
	return (str[ft_strlen(str) - 1]);
}
