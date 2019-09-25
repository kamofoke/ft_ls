# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 11:04:05 by kamofoke          #+#    #+#              #
#    Updated: 2019/09/16 17:39:21 by kamofoke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =ft_ls.a


FLAGS = -Wall -Wextra -Werror -o ft_ls

SRCS = srcs/main.c \
			srcs/ft_printcolor.c \
			srcs/ft_checks.c \
			srcs/ft_flags.c \
			srcs/ft_path.c \
			srcs/ft_print.c \
			srcs/ft_printpermissions.c \
			srcs/ft_lg_r.c \
			srcs/ft_list.c \
			srcs/ft_list_swap.c \
			srcs/ft_sort.c \
			srcs/ft_selected.c \
			srcs/ft_block.c \
			srcs/ft_access.c \
			srcs/ft_modify.c \
			srcs/ft_free.c \
			srcs/ft_exit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME):  $(OBJS)
	make -C Libft
	gcc $(FLAGS) $(SRCS) -I Libft/libft.h Libft/libft.a
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
