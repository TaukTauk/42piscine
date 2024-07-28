/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:04:33 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/28 21:16:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void int_to_str(int number, char *num_str)
{
    int len = 0;
    int tmp = number;

    if (number == 0)
    {
        num_str[len++] = '0';
        num_str[len] = '\0';
        return;
    }
    while (tmp > 0)
    {
        tmp /= 10;
        len++;
    }
    tmp = number;
    num_str[len] = '\0';
    while (len > 0)
    {
        num_str[--len] = '0' + (tmp % 10);
        tmp /= 10;
    }
}

char *get_line_end(char *ls, char *buffer, size_t bsize)
{
    char *le = ls;
    while (le < buffer + bsize && *le != '\n')
        le++;
    return le;
}

char *get_colon_pos(char *ls, char *le)
{
    char *col = ls;
    while (col < le && *col != ':')
        col++;
    return col;
}

int extract_number(char *ls, char *col)
{
    int num = 0;
    char *ptr = ls;

    while (ptr < col)
    {
        if (*ptr >= '0' && *ptr <= '9')
            num = num * 10 + (*ptr - '0');
        ptr++;
    }
    return num;
}
char *ft_extract_word(char *col, char *le)
{
    char word[CHUNK_SIZE];
    size_t i = 0;
    char *res;
    char *ptr = col + 1;

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
    return res;
}
