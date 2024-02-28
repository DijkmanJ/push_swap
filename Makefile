# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdijkman <jdijkman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/25 14:45:41 by jdijkman      #+#    #+#                  #
#    Updated: 2024/02/16 14:58:02 by jdijkman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = list_utils.c main.c operations.c utils.c simple_sort.c index_list.c radix.c

PRINTF_PATH = ./printf

PRINTF = $(PRINTF_PATH)/libftprintf.a

RM = rm -rf

CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g

OBJ = $(SRC:%.c=%.o)

all:				$(NAME)

$(NAME):			$(PRINTF) $(SRC)
					cc $(SRC) $(PRINTF) -o $(NAME)

$(PRINTF):
					make -C $(PRINTF_PATH) all -s

clean:
					make -C $(PRINTF_PATH) clean -s
					$(RM) $(NAME)

fclean:				clean
					make -C $(PRINTF_PATH) fclean -s
					$(RM) $(NAME)

re: fclean all

.PHONY:				all bonus clean fclean re libft main