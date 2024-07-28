/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:16:29 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/28 21:22:20 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_alloc(size_t size)
{
    char *buffer = (char *)malloc(size);
    if (buffer == NULL)
        ft_putstr("Error\n");
    return buffer;
}

void ft_strncpy(char *dest, const char *src, size_t size)
{
    size_t i = 0;
    while (i < size && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < size)
    {
        dest[i++] = '\0';
    }
}

char *ft_expand(char *buffer, size_t *bsize, size_t total)
{
    char *new_buffer;

    *bsize *= 2;
    new_buffer = ft_alloc(*bsize);
    if (new_buffer == NULL)
    {
        free(buffer);
        return NULL;
    }
    ft_strncpy(new_buffer, buffer, total);
    free(buffer);
    return new_buffer;
}

int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res * sign;
}
