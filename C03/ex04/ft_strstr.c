/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:07:01 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/14 13:45:18 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (to_find[i] != '\0')
	{
		while (to_find[i] != str[j])
		{
			j++;
		}
		i++;
	}
	while (str[j] != '\0')
	{
		to_find[i] = str[j];
		i++;
		j++;
	}
	return (to_find);
}
