# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 18:49:31 by zwang             #+#    #+#              #
#    Updated: 2018/09/20 09:45:18 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
LIBFT = libft.a

RESET = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m


all: $(LIBFT) $(PUSH_SWAP) $(CHECKER)

$(LIBFT):
	@make -C srcs/libft/
	@mv srcs/libft/libft.a .

$(PUSH_SWAP):
	@make -C srcs/push_swap/ p
	@mv srcs/push_swap/push_swap .

$(CHECKER):
	@make -C srcs/checker/ c
	@mv srcs/checker/checker .

clean:
	@make -C srcs/libft/ clean
	@make -C srcs/push_swap/ clean
	@make -C srcs/checker/ clean

fclean: clean
	@rm -rf $(LIBFT)
	@printf "\033[1;31m[x] $(RESET)\x1B[31m$(LIBFT) deleted\n"
	@rm -rf $(PUSH_SWAP)
	@printf "\033[1;31m[x] $(RESET)\x1B[31m$(PUSH_SWAP) deleted\n"
	@rm -rf $(CHECKER)
	@printf "\033[1;31m[x] $(RESET)\x1B[31m$(CHECKER) deleted\n"

re: fclean all

.PHONY: all clean fclean re
