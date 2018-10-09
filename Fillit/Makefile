# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 15:54:57 by zwang             #+#    #+#              #
#    Updated: 2018/09/11 10:46:55 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRCS_DIR = srcs/
OBJS_DIR = objs/

FILLIT_INCS = incs/
LIBFT_INCS = srcs/libft/incs/

INCS = -I $(FILLIT_INCS) -I $(LIBFT_INCS)
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(patsubst srcs/%.c, %.o, $(SRCS))


all: $(NAME)

$(NAME):
	@make -C ./srcs/libft
	@mv ./srcs/libft/libft.a .
	@$(CC) -g $(CFLAGS) -c $(SRCS) $(INCS)
	@$(CC) -g -o $(NAME) $(OBJS) ./libft.a
	@mkdir -p $(OBJS_DIR)
	@mv $(OBJS) $(OBJS_DIR)

clean:
	@make -C ./srcs/libft clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C ./srcs/libft fclean
	@rm -rf $(NAME)
	@rm -rf ./libft.a

re: fclean all

do:
	./fillit test/valid.fillit
	./fillit test/invalid.fillit

.PHONY: all clean fclean re
