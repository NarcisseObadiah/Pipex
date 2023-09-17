# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 03:51:00 by mobadiah          #+#    #+#              #
#    Updated: 2023/09/17 17:15:58 by mobadiah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex
SRC			:=	utils.c pipex.c
LIBFT		:= ./libft
OBJ			:= $(SRC:.c=.o)
CC			:=	cc
CFLAGS		:= -Wall -Werror -Wextra
HEADERS	:= -Iinclude -lglfw 

all:$(NAME) 

$(NAME):build_libft $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT)/libft.a $(HEADERS)\
	 -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT)

build_libft:
	@make -C $(LIBFT)

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(LIBFT)/libft.a
	@rm -f $(NAME)

re: fclean all

.PHONY: pipex,  build_libft, all, clean, fclean, re