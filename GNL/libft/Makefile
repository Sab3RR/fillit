#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkulahin <rkulahin@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 18:31:25 by rkulahin          #+#    #+#              #
#    Updated: 2018/10/23 18:31:27 by rkulahin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libft.a
SRCS=*.c
OBJECTS=*.o

all: $(NAME)

$(NAME):
	gcc -I . -c $(SRCS) -Wall -Wextra -Werror
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all