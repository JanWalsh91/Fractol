# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgros <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 17:02:59 by tgros             #+#    #+#              #
#    Updated: 2017/01/16 17:03:41 by tgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT_NAME = libft.a

SRC_PATH = src/
INC_PATH = inc/
LIB_PATH = Libft/

SRC_NAME = fractol

SRC_NAME_PATH = $(addprefix $(SRC_PATH), $(SRC_NAME))
SRC = $(addsuffix $(EXT), $(SRC_NAME_PATH))

OBJ = $(SRC:.c=.o)

EXT = .c
CC	= gcc
FLG = -Werror -Wextra -Wall
MLX = -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

%.o : %.c
	@$(CC) $(FLG) -I$(INC_PATH) -I$(LIB_PATH) -c -o $@ $^ 

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLG) $(MLX) $(LIB_PATH)$(LIBFT_NAME) $(OBJ) -o $(NAME)
	@echo "fractol: done"

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
