# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 12:16:14 by mvaldes           #+#    #+#              #
#    Updated: 2021/06/02 12:26:26 by mvaldes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

SRCS =	push_swap.c \
		check_n_parse.c \
		utils.c \
		utils_1.c \
		utils_2.c \
		sort_prms.c \
		operations.c \
		exec_n_print.c \
		sort_prms_rules.c

OBJS = $(SRCS:.c=.o)
CC = @gcc
RM = @/bin/rm -f
CC_FLAGS = -Wall -Wextra -Werror -I.
LIBFT = libft/libft.a

all:		$(NAME)

$(NAME):	compile $(OBJS)
			$(CC) $(CC_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "compile done"

compile:
			@make -C libft

clean:
			@make clean -C libft
			$(RM) $(OBJS)
			@echo "Del done"

fclean:		clean
			@make fclean -C libft
			$(RM) $(NAME)
			@echo "Del done"

re:			fclean all

.PHONY: clean fclean re compile all