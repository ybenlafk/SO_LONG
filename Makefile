# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:21:51 by ybenlafk          #+#    #+#              #
#    Updated: 2023/01/07 15:38:44 by ybenlafk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
BNAME= so_long_bonus

HEADER= so_long.h

SRCS= mandatory/get_next_line.c mandatory/moves.c mandatory/utils.c mandatory/parsing.c mandatory/images.c mandatory/main.c
BSRCS= bonus/get_next_line.c bonus/moves.c bonus/utils.c bonus/parsing.c bonus/images.c bonus/main.c
OBGJ= $(SRCS:.c=.o)
BOBGJ= $(BSRCS:.c=.o)
CC= cc
CFLAGS= -lmlx -framework OpenGL -framework AppKit
FLAGS= -Imlx
FRM= rm -rf

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBGJ)
	$(CC) $(OBGJ) $(CFLAGS) -o $(NAME)

$(BNAME): $(BOBGJ)
	$(CC) $(BOBGJ) $(CFLAGS) -o $(BNAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(FRM) $(OBGJ) $(BOBGJ)

fclean: clean
	$(FRM) $(NAME) $(BNAME)

re: fclean all