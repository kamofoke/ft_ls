# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 11:04:05 by kamofoke          #+#    #+#              #
#    Updated: 2019/09/10 11:06:26 by kamofoke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a

FLAGS = -c -Wall -Wextra -Werror

SRCS = ./src/*.c

OBJS = $(SRCS: .c=.o)			

all : $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
