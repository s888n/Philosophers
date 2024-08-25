# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srachdi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 23:00:48 by srachdi           #+#    #+#              #
#    Updated: 2023/05/26 23:00:59 by srachdi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread #-fsanitize=thread
RM = rm -rf
SRCS = main.c  init.c actions.c time.c msg.c utils.c error.c simulation.c end.c
OBJS =  $(SRCS:.c=.o)
INCLUDES = philo.h

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)

re : fclean all
.PHONY : all clean fclean re
