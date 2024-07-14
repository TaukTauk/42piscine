/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:51:54 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/14 14:16:31 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	j = ft_strlen(dest);
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size < dlen || size == 0)
	{
		return (size + slen);
	}
	while (src [i] != '\0' && i < size - dlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (slen + dlen);
}
