# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srachdi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 11:16:09 by srachdi           #+#    #+#              #
#    Updated: 2023/05/26 11:16:13 by srachdi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread
INCLUDES = philo_bonus.h
SRCS = main_bonus.c init_bonus.c end_bonus.c actions_bonus.c time_bonus.c sim_bonus.c utils_bonus.c msg_bonus.c
RM  = rm -rf
OBJS = $(SRCS:.c=.o)

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
