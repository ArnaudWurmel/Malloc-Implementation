##
## Makefile for  in /home/wurmel/rendu/PSU_2015_my_printf
## 
## Made by Arnaud WURMEL
## Login   <wurmel_a@epitech.net>
## 
## Started on  Mon Nov  2 12:51:22 2015 Arnaud WURMEL
## Last update Tue Jan 24 14:27:09 2017 Arnaud WURMEL
##

cc=	gcc

RM=	rm -f

CFLAGS+=-Wextra -Wall -Werror -fPIC

CFLAGS+= -I./include

NAME=	libprintf.a

SRCS=	my_printf.c \
	my_put_nbr.c \
	my_put_nbr_base.c \
	my_putchar.c \
	my_putstr.c \
	treatement_dieze.c \

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
