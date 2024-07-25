# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 16:27:09 by talin             #+#    #+#              #
#    Updated: 2024/07/25 10:10:05 by talin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a
gcc -Wall -Werror -Wextra -c *.c
ar rcs libft.a *.o
rm -r *.o
