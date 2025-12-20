# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khebert <khebert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 13:58:12 by khebert           #+#    #+#              #
#    Updated: 2025/12/19 14:18:28 by khebert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap.a
LIBFT_DIR 	= ./Libft
LIBFT 		= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
rm			= rm -f

SRC			=	ft_parsing.c 			\
				ft_push.c 				\
				ft_reverse_rotate.c 	\
				ft_rotate.c 			\
				ft_struct.c 			\
				ft_swap.c 				\
	
OBJ 		= $(SRC:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(LIBFT):
		@echo "Compiling Libft..."
		@make -C $(LIBFT_DIR) > /dev/null
		
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)The $(RED)$(NAME)$(GREEN) has been built !"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@
	@make -C $(LIBFT_DIR) clean > /dev/null
	@
	@$(RM) $(OBJ)
	@echo "$(RED)Objects $(GREEN)removed."

fclean: clean
	@
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@
	@$(RM) $(NAME)
	@echo "$(RED)Full clean $(GREEN)done."
	
re:: fclean all

.PHONY: all clean fclean re