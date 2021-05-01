# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikang <jikang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 20:30:08 by jikang            #+#    #+#              #
#    Updated: 2020/07/08 16:04:56 by jikang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	=	ft_printf.c \
			set_info_func.c \
			length_by_base.c \
			display_conv_c.c \
			display_conv_d.c \
			display_conv_s.c \
			display_conv_p.c \
			display_conv_u.c \
			display_conv_hex.c \
			display_conv_pcnt.c
			
OBJS	= $(SRC:.c=.o)

NAME	= libftprintf.a
LIBFT	= libft
LIBFT.A	= libft.a
RM		= rm -rf
LIB		= ar rc 
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all 	: $(NAME)

clean	: 
		$(RM) $(OBJS) *.gch a.out
		make clean -C $(LIBFT)

fclean	: clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re		: fclean all

$(NAME) : $(OBJS)
		make -C $(LIBFT)
		cp $(LIBFT)/$(LIBFT.A) $@
		$(LIB) $@ $^