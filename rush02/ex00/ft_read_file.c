/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:51:41 by talin             #+#    #+#             */
/*   Updated: 2024/07/28 17:17:04 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_return(int nb, char *buffer)
{
	if (nb == -1)
	{
		ft_putstr("Error\n");
		free(buffer)
		return (0);
	}
}

char	*ft_chunk(int fd, char *buffer, size_t *total, size_t *bsize)
{
	ssize_t	b_read;
	char	chunk[CHUNK_SIZE];
	size_t	i;

	b_read = read(fd, chunk, CHUNK_SIZE);
	while (b_read > 0)
	{
		if (*total + b_read >= *bsize)
		{
			buffer = ft_expand(buffer, bsize, *total);
			if (buffer == NULL)
			{
				close (fd);
				return (0);
			}
		}
		i = -1;
		while (++i < b_read)
			buffer[*total + i] = chunk[i];
		*total += b_read;
		b_read = read(fd, chunk, CHUNK_SIZE);
	}
	if (b_read == -1)
		ft_putstr("Error\n");
	return (buffer);
}

char	*ft_read(const char *filename, size_t *out_size)
{
	int			fd;
	size_t		bsize;
	size_t		total;
	char		*buffer;

	bsize = INITIAL_BUFFER_SIZE;
	total = 0;
	buffer = ft_alloc(bsize);
	if (buffer == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	ft_return(fd, &buffer);
	buffer = ft_chunk(fd, buffer, &total, &bsize);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	buffer[total] = '\0';
	*out_size = total;
	close(fd);
	return (buffer);
}
