# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 13:07:31 by jwalsh            #+#    #+#              #
#    Updated: 2017/01/31 17:10:39 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_abs.c \
		ft_power.c \
		ft_round.c \
		ft_rgb_mix.c \
		ft_to_radian.c \
		new_matrix4.c \
		new_identity_matrix4.c \
		new_scaling_matrix4.c \
		new_rotation_matrix4.c \
		matrix4_product.c \
		vec3_matrix4_product.c \
		matrix4_translation.c \
		vec3_dot.c \
		vec3_length.c \
		vec3_normalize.c \
		vec3_cross_product.c \
		vec3_add.c \
		vec3_subtract.c \
		vec3_product.c \
		c_add.c \
		c_add_float.c \
		c_abs.c \
		c_divide.c \
		c_product.c \
		c_product_double.c \
		c_minus.c \
		c_minus_double.c \
		c_modulus.c \
		c_sin.c \
		c_sphere.c \
		c_horseshoe.c \
		c_swirl.c \
		c_polar.c


NAME = libmathft.a

HEAD = libmathft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

ECHO = echo

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

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(ECHO) "$(C_CYAN)Libmathft compilation done.$(C_NONE)"

compile_msg:
	@$(ECHO) "$(C_CYAN)Compiling Libamthft . . .$(C_NONE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(ECHO) "$(C_CYAN)Libmathft clean done.$(C_NONE)"

fclean: clean
	@rm -f $(NAME)
	@$(ECHO) "$(C_CYAN)Libmathft fclean done.$(C_NONE)"

re: fclean
	@$(MAKE) all

.PHONY: clean fclean
	@$(ECHO) "$(C_CYAN)Libmathft .PHONY done.$(C_NONE)"
