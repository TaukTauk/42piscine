/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:14:01 by hsoe              #+#    #+#             */
/*   Updated: 2024/07/29 12:22:53 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_filesize(char *filename)
{
	int	n;
	int	fopen;
	char	c;

	n = 0;
	fopen = open(filename, O_RDONLY);
	if (fopen < 0)
		return (0);
	while (read(fopen, &c, 1) > 0)
		n++;
	close(fopen);
	return (n);
}

char	*read_file(char *filename)
{
	int	fopen;
	int	i;
	int	n;
	char	*str;
	char	c;

	n = ft_filesize(filename);
	i = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	fopen = open(filename, O_RDONLY);
	if (fopen < 0)
		return (0);
	while (read(fopen, &c, 1) > 0)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	close(fopen);
	return (str);
}
