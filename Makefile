NAME	   := pipex
NAME_BONUS := pipex_bonus
SRC        := utils.c pipex.c fd_close_all_fd.c
SRC_BONUS  := utils_bonus.c pipex_bonus.c utils.c
LIBFT      := ./libft
OBJ        := $(SRC:.c=.o)
OBJ_BONUS  := $(SRC_BONUS:.c=.o)
CC         := gcc
CFLAGS     := -Wall -Werror -Wextra
LDFLAGS    := -L$(LIBFT) -lft
HEADERS    := -Iinclude

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): build_libft $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): build_libft $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(CFLAGS) $(LDFLAGS) $(HEADERS) -o $(NAME_BONUS)


$(LIBFT):
	@make -C $(LIBFT)

build_libft:
	@make -C $(LIBFT)

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME) $(NAME)_bonus

re: fclean all

# re_bonus:	fclean bonus

.PHONY: all clean fclean re bonus
