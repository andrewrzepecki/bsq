# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 15:51:13 by anrzepec          #+#    #+#              #
#    Updated: 2018/09/17 16:03:33 by anrzepec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	BSQ

SRC 	= 	$(wildcard srcs/*.c main.c)

OBJS	=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	+=  -Werror -Wall -Wextra

INCL	=	Iincludes

RM		=	rm -f

all		: 	$(NAME)
			make clean

%.o		: 	%.c	
			$(CC) $(CFLAGS) -c $< -o $@ -$(INCL)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
