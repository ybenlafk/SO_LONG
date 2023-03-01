# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:21:51 by ybenlafk          #+#    #+#              #
#    Updated: 2023/01/08 22:15:55 by ybenlafk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
BNAME= so_long_bonus

HEADER= so_long.h

SRCS= mandatory/get_next_line.c mandatory/moves.c mandatory/utils.c \
		mandatory/utils1.c mandatory/utils2.c mandatory/utils3.c mandatory/parsing.c mandatory/images.c mandatory/main.c
BSRCS= bonus/get_next_line.c bonus/moves.c bonus/utils.c bonus/parsing.c \
		bonus/utils1.c bonus/utils2.c bonus/utils3.c bonus/utils4.c bonus/images.c bonus/main.c bonus/itoa.c
OBGJ= $(SRCS:.c=.o)
BOBGJ= $(BSRCS:.c=.o)
CC= cc
CFLAGS= -lmlx -framework OpenGL -framework AppKit
FLAGS=  -Wall -Wextra -Werror -Imlx

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBGJ)
	$(CC) $(OBGJ) $(CFLAGS) -o $(NAME)

$(BNAME): $(BOBGJ)
	$(CC) $(BOBGJ) $(CFLAGS) -o $(BNAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBGJ) $(BOBGJ)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all