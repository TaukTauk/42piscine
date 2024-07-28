/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:36:36 by talin             #+#    #+#             */
/*   Updated: 2024/07/28 16:51:29 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

char	*ft_alloc(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc(size);
	if (buffer == NULL)
		ft_putstr("Error\n");
	return (buffer);
}

void	ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i] != '0')
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_expand(char *buffer, size_t *bsize, size_t total)
{
	char	*new;

	*bsize *= 2;
	new = ft_alloc(*bsize);
	if (new == NULL)
	{
		free (buffer);
		return (0);
	}
	ft_strncpy(new, buffer, total);
	free(buffer);
	return (new);
}
