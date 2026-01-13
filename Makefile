# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khebert <khebert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 13:58:12 by khebert           #+#    #+#              #
#    Updated: 2026/01/13 23:26:59 by khebert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT_DIR 	= ./Libft
LIBFT 		= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
rm			= rm -f

SRC			=	ft_algo.c				\
				ft_condition.c 			\
				ft_cost.c				\
				ft_libft.c 				\
				ft_parsing.c 			\
				ft_push.c 				\
				ft_reverse_rotate.c 	\
				ft_rotate.c 			\
				ft_split.c 				\
				ft_struct.c 			\
				ft_swap.c 				\
				ft_turk.c				\
	
OBJ 		= $(SRC:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME) clean

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)The $(RED)$(NAME)$(GREEN) has been built !"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)Objects $(GREEN)removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Full clean $(GREEN)done."
	
re:: fclean all

.PHONY: all clean fclean re