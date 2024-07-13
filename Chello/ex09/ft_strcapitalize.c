/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:02:58 by talin             #+#    #+#             */
/*   Updated: 2024/07/13 18:53:43 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if (i == 0 && (str[i] >= 97 && str[i] <= 122))
	{
		str[i] -= 32;
	}
	while (str[i] != '\0')
	{
		if ((str[i - 1] == ' ' || str[i - 1] == ',' || str[i - 1] == '?' \
				|| str[i - 1] == '-' || str[i - 1] == '+' || str[i - 1] == ';') \
				&& (str[i] >= 97 && str[i] <= 122))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
