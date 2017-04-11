##
## Makefile for  in /home/wurmel/rendu/PSU_2016_malloc
## 
## Made by Arnaud WURMEL
## Login   <wurmel_a@epitech.net>
## 
## Started on  Mon Jan 23 16:25:24 2017 Arnaud WURMEL
## Last update Wed Feb  8 20:26:14 2017 Arnaud WURMEL
##

SRCS_PATH=	src/

SRCS=		$(SRCS_PATH)malloc.c \
		$(SRCS_PATH)heap_manager.c \
		$(SRCS_PATH)show_alloc.c \
		$(SRCS_PATH)realloc.c \
		$(SRCS_PATH)free.c

OBJS=		$(SRCS:.c=.o)

CFLAGS+=	-Wall -Wextra -Werror -fpic -I ./include

NAME=		libmy_malloc.so

CC=		gcc

$(NAME):	$(OBJS)
		make -C $(SRCS_PATH)/my_printf/
		$(CC) -shared -o $(NAME) $(OBJS) -L $(SRCS_PATH)my_printf -lprintf

all:		$(NAME)

clean:
		rm -rf $(OBJS)
		make -C $(SRCS_PATH)/my_printf/	clean

fclean:		clean
		rm -rf $(NAME)
		make -C $(SRCS_PATH)/my_printf/ fclean

re:		fclean all
