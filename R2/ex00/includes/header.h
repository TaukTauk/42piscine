/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <talin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:02:36 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/28 21:26:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define INITIAL_BUFFER_SIZE 1024
# define CHUNK_SIZE 1024

char	*ft_find_word(int number, char *buffer, size_t bsize);
int		ft_return(int nb, char *buffer);
char	*ft_chunk(int fd, char *buffer, size_t *total, size_t *bsize);
char	*ft_read(const char *filename, size_t *out_size);
char	*ft_extract_word(char *col, char *le);
void	int_to_str(int number, char *num_str);
char	*get_line_end(char *ls, char *buffer, size_t bsize);
char	*get_colon_pos(char *ls, char *le);
int		extract_number(char *ls, char *col);
int		ft_num_len(int number);
void	ft_putstr(char *str);
int		ft_strlen(const char *str);
char	*ft_alloc(size_t size);
void	ft_strncpy(char *dest, const char *src, size_t size);
char	*ft_expand(char *buffer, size_t *bsize, size_t total);
char	*find_word(int number, const char *filename);
int		ft_atoi(const char *str);
#endif
