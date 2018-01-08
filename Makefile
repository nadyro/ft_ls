# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 15:51:04 by nsehnoun          #+#    #+#              #
#    Updated: 2017/11/21 21:42:38 by nsehnoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  printer.c \
	  args_checker.c \
	  args_factory.c \
	  path_sorting.c \
	  dir_factory.c \
	  manage_list.c \
	  dirs_infos.c \
	  lmanager.c \
	  sorting.c \
	  chmod_manager.c \
	  deleg_printer.c \
	  deleg_args.c \
	  second_printer.c \

NAME = ft_ls

LIB = -Llibft -lft

HEADERS = ft_ls.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	gcc -o $(NAME) $(OBJ) $(LIB) -I $(HEADERS)

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
