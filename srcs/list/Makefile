# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptycho <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 14:00:52 by ptycho            #+#    #+#              #
#    Updated: 2020/11/01 14:00:58 by ptycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =   ft_create_elem.c \
					ft_list_at.c \
					ft_list_clear.c \
					ft_list_find.c \
					ft_list_foreach.c \
					ft_list_foreach_if.c \
					ft_list_last.c \
					ft_list_merge.c \
					ft_list_push_back.c \
					ft_list_push_front.c \
					ft_list_remove_if.c \
					ft_list_reverse.c \
					ft_list_size.c \
					ft_list_operation.c

OBJS            = $(SRCS:.c=.o)
CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.
NAME            = ft_list.a

all: $(NAME)

%.o:%.c ft_list.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:         all clean fclean re