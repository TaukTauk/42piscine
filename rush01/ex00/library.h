/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:51:26 by talin             #+#    #+#             */
/*   Updated: 2024/07/21 16:08:21 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int	ft_atoi(char *str);
int	ft_check_view(int grid[4][4], int index, int input[16]);
int	ft_check(int grid[4][4], int index, int num);
int	*ft_input(char *str);
int	ft_strlen(char *str);
