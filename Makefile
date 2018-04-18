##
## Makefile for $ in /home/Kitero/delivery/CPool_rush3
## 
## Made by Theo CLEMENT
## Login   <Kitero@epitech.net>
## 
## Started on  Sat Oct 29 19:46:06 2016 Theo CLEMENT
## Last update Wed Dec 14 14:35:20 2016 Theo CLEMENT
##

CC	= gcc

RM	= rm -f

NAME	= bsq

SRCS	= main.c	\
	  convert.c	\
	  my_putchar.c	\
	  linkmain.c

OBJS    = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
