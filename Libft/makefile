# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 13:07:31 by jwalsh            #+#    #+#              #
#    Updated: 2017/01/23 12:53:53 by tgros            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_ispunct.c \
	ft_isspace.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_strrev.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_islower.c \
	ft_isupper.c \
	ft_strjoinfree.c \
	ft_clamp.c \
	get_next_line.c \
	ft_range.c \
	ft_straddchar.c \
	ft_straddcharfree.c \
	ft_error.c \
	ft_itoa_base.c \
	ft_uitoa_base.c \
	ft_strtolower.c \
	ft_strtoupper.c \
	ft_wstrlen.c \
	ft_strsjoin.c \
	ft_strappend.c \
	ft_wstrappend.c \
	ft_wstrnew.c \
	ft_wstrsjoin.c \
	ft_strsjoinfree.c \
	ft_strappendfree.c \
	ft_wstrappendfree.c \
	ft_wstrsjoinfree.c \
	ft_putwchar.c \
	ft_putwchar_fd.c \
	ft_putwstr_fd.c \
	ft_putwstr_fd.c \
	ft_ustrnew.c \
	ft_wctostr.c \
	ft_ustrjoin.c \
	ft_ustrjoinfree.c \
	ft_ustrncat.c \
	ft_wstrtostr.c \
	ft_ustrappend.c \
	ft_ustrsjoin.c \
	ft_ustrappendfree.c \
	ft_ustrsjoinfree.c \
	ft_ustrncpy.c \
	ft_ustrcpy.c \
	ft_ustrdup.c \
	ft_swap.c \
	ft_ustrlen.c \
	ft_strdupfree.c \
	ft_ustrdupfree.c \
	ft_error_exit.c \
	ft_strcmp_percent.c \
	ft_increment_index.c

NAME = libft.a

HEAD = libft.h

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
	@$(ECHO) "$(C_CYAN)Libft compilation done.$(C_NONE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./libft.h

clean:
	@rm -f $(OBJ)
	@$(ECHO) "$(C_CYAN)Libft clean done.$(C_NONE)"

fclean: clean
	@rm -f $(NAME)
	@$(ECHO) "$(C_CYAN)Libft fclean done.$(C_NONE)"

re: fclean
	@$(MAKE) all

.PHONY: clean fclean
	@$(ECHO) "$(C_CYAN)Libft .PHONY done.$(C_NONE)"
