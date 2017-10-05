# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlouar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 15:40:57 by hlouar            #+#    #+#              #
#    Updated: 2016/05/16 16:15:07 by hlouar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = src/main.c src/setterm.c src/resizewin.c src/tools.c src/move.c\
		src/tools2.c src/signal.c src/listefunc.c src/tools3.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBS = libft/libft.a

LNCURSES = -lncurses

$(NAME):$(OBJ)
		@cd libft && make re && cd ..
		@gcc $(LNCURSES) $(FLAG) -o $(NAME) $(SRC) $(LIBS) -I.

all: $(NAME)

clean:
		@cd libft && make clean && cd ..
		@/bin/rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean && cd ..
	@/bin/rm -f $(NAME)

re:	fclean all
