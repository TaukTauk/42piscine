/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:40:28 by talin             #+#    #+#             */
/*   Updated: 2024/07/30 14:54:42 by talin            ###   ########.fr       */
/*   Updated: 2024/07/30 11:40:13 by hsoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_grid
{
	int	x;
	int	y;
	int	max;
}	t_grid;

char			**ft_split(char *str, char *charset);
char			*read_file(char *filename);
int				**ft_grid(char **str);
char			ft_find_empty(char *str);
char			ft_find_obst(char *str);
char			ft_find_full(char *str);
int				ft_strlen(char *str);
int				ft_gridheight(char **grid);
int				**ft_grid(char **map);
int				ft_filesize(char *filename);
void			ft_putchar(char c);
void			ft_putstr(char *str);
struct t_grid	ft_largest(int **grid, char **map);
void			ft_fill(char **map, struct t_grid res);
void			ft_print_map(char **map, int rows, int cols);
int				ft_lineno(char *str);
int				ft_valid(char **map);
#endif
