#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmery <jmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:56:49 by jmery             #+#    #+#              #
#    Updated: 2014/01/19 19:26:04 by jmery            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB = srcs/

FLAG = -Wall -Wextra -Werror

NAME = computorv2

SRCS = 	$(LIB)computorv1/computor_v1.c \
		$(LIB)computorv1/computor_v1_2.c \
		$(LIB)computorv1/computor_v1_3.c \
		$(LIB)computorv1/equ.c \
		$(LIB)computorv1/equ_2.c \
		$(LIB)computorv1/free.c \
		$(LIB)computorv1/print.c \
		$(LIB)computorv1/resolve.c \
		$(LIB)computorv1/resolve_2.c \
		$(LIB)computorv1/get_next_line.c \
		$(LIB)computorv1/parts.c \
		$(LIB)computorv1/term.c \
		$(LIB)computorv1/terms.c \
		$(LIB)computorv1/tools.c \
		$(LIB)computorv1/tools_2.c \
		$(LIB)bracket.c \
		$(LIB)bracket_2.c \
		$(LIB)check.c \
		$(LIB)clean.c \
		$(LIB)clean_line.c \
		$(LIB)computorv2.c \
		$(LIB)data.c \
		$(LIB)exp_split.c \
		$(LIB)ft_ftoa.c \
		$(LIB)func.c \
		$(LIB)get_value.c \
		$(LIB)mat.c \
		$(LIB)param.c \
		$(LIB)power.c \
		$(LIB)print.c \
		$(LIB)reduce_equ.c \
		$(LIB)resolution.c \
		$(LIB)resolve.c \
		$(LIB)resolve_equ.c \
		$(LIB)resolve_equ_2.c \
		$(LIB)sign.c \
		$(LIB)signal.c \
		$(LIB)split_value.c \
		$(LIB)tools.c \
		$(LIB)tools_2.c \
		$(LIB)var.c \
		$(LIB)var_2.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJS) -L. libft/libft.a

%.o: %.c
	gcc $(FLAG) -c $< -o $@ -I includes

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	rm -f ./libft/libft.a
	rm -f computorv2

re: fclean all

