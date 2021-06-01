# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 11:18:52 by mvaldes           #+#    #+#              #
#    Updated: 2021/06/01 11:35:41 by mvaldes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c\
			ft_atoi.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_putchar_fd.c\
			ft_strdup.c\
			ft_substr.c\
			ft_memcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

RM	= rm -f

.c.o: $(SRCS)
	gcc -Wall -Wextra -Werror -fsanitize=address -g -c $^ -o ${^:.c=.o}

$(NAME):    $(OBJS) libft.h
	ar rcs $(NAME) $(OBJS)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
