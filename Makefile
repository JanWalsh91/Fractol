# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgros <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 17:02:59 by tgros             #+#    #+#              #
#    Updated: 2017/01/18 11:20:52 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT_NAME = libft.a
LIBMATHFT_NAME = libmathft.a

SRC_PATH = src/
INC_PATH = include/
LIB_PATH = Libft/
LIBMATH_PATH = Libmathft/

SRC_NAME = main \
			fractol \
			draw \
			mandelbrot \
			init_fractal \
			init_names \
			init_win \
			calc_colors \
			key_released \
			debug

SRC_NAME_PATH = $(addprefix $(SRC_PATH), $(SRC_NAME))
SRC = $(addsuffix $(EXT), $(SRC_NAME_PATH))

OBJ = $(SRC:.c=.o)

EXT = .c
CC	= gcc
FLG = -Werror -Wextra -Wall
MLX = -lmlx -framework OpenGL -framework AppKit 

C_NONE = \033[0m
C_BOLD = \033[1m
C_BLACK = \033[30m
C_RED = \033[31m
C_GREEN = \033[32m
C_BROWN = \033[33m
C_BLUE = \033[34m
C_MAGENTA = \033[35m
C_CYAN = \033[36m
C_GRAY = \033[37m

ECHO = echo

all: $(NAME)

%.o : %.c
	@$(CC) $(FLG) -I$(INC_PATH) -I$(LIB_PATH) -I$(LIBMATH_PATH) -c -o $@ $^

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@make -C $(LIBMATH_PATH)
	@$(CC) $(FLG) $(MLX) $(LIB_PATH)$(LIBFT_NAME) $(LIBMATH_PATH)$(LIBMATHFT_NAME) $(OBJ) -o $(NAME)
	@rm -rf src/*.o
	@$(ECHO) "$(C_GREEN)Fractol compilation done.$(C_NONE)"

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIB_PATH) clean
	@$(ECHO) "$(C_GREEN)Fractol clean done.$(C_NONE)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@$(ECHO) "$(C_GREEN)Fractol fclean done.$(C_NONE)"

re: fclean all

PHONY : re all clean fclean
	@$(ECHO) "$(C_GREEN)Fractol .PHONY done.$(C_NONE)"

.PHONY: all clean fclean re
