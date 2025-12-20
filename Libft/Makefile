# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khebert <khebert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 16:03:00 by khebert           #+#    #+#              #
#    Updated: 2025/12/19 14:11:01 by khebert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
rm		= rm -f

SRC		=	ft_isalpha.c 	\
			ft_isdigit.c 	\
			ft_isalnum.c 	\
			ft_isascii.c 	\
			ft_isprint.c 	\
			ft_strlen.c 	\
			ft_memset.c 	\
			ft_bzero.c 		\
			ft_memcpy.c 	\
			ft_memmove.c 	\
			ft_strlcpy.c 	\
			ft_strlcat.c 	\
			ft_toupper.c 	\
			ft_tolower.c 	\
			ft_strchr.c 	\
			ft_strrchr.c 	\
			ft_strncmp.c 	\
			ft_memchr.c 	\
			ft_memcmp.c		\
			ft_strnstr.c 	\
			ft_atoi.c 		\
			ft_substr.c		\
			ft_strdup.c		\
			ft_calloc.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c \
			ft_putnbr_fd.c	\
			ft_strmapi.c	\
			ft_striteri.c	\

SRC_BONUS	=	ft_lstnew_bonus.c				\
				ft_lstsize_bonus.c				\
				ft_lstadd_front_bonus.c			\
				ft_lstadd_back_bonus.c			\
				ft_lstclear_bonus.c				\
				ft_lstdelone_bonus.c			\
				ft_lstiter_bonus.c				\
				ft_lstlast_bonus.c				\
				ft_lstmap_bonus.c				\

SRC_ALL	= $(SRC) $(SRC_BONUS)
	
OBJ 	= $(SRC:.c=.o)

OBJ_BONUS	= $(SRC_BONUS:.c=.o)

OBJ_ALL	= $(SRC_ALL:.c=.o)

all: $(NAME)

GREEN_COLOR = \033[0;32m

RED_COLOR = \033[0;31m

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo -e '$(GREEN_COLOR)The$(RED_COLOR) $(NAME)$(GREEN_COLOR) as been built !'

bonus: $(OBJ_ALL)
	$(AR) $(NAME) $(OBJ_ALL)
	@echo -e '$(GREEN_COLOR)The$(RED_COLOR) $(NAME) with BONUS$(GREEN_COLOR) as been built !'

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_ALL)

fclean: clean
	$(RM) $(NAME)

re:: fclean all

.PHONY: all clean fclean re