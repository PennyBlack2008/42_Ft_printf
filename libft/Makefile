# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikang <jikang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 09:08:53 by jikang            #+#    #+#              #
#    Updated: 2020/07/08 17:31:32 by jikang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_isdigit.c \
				ft_pow.c \
				ft_put_cap_hex.c \
				ft_put_small_hex.c \
				ft_putchar_fd.c \
				ft_putnbr_fd_u.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strlen.c \
				ft_safer_free.c


OBJS		= $(SRC:.c=.o)

NAME		= libft.a
RM			= rm -f
LIB			= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all		: $(NAME)

bonus	: $(NAME) $(OBJS)
		$(LIB) $^

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

$(NAME) : $(OBJS)
		$(LIB) $@ $^

.PHONY: bonus all clean fclean re
