# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moakouda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 17:32:25 by moakouda          #+#    #+#              #
#    Updated: 2021/10/13 17:32:33 by moakouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c ft_atoi.c utils.c utils_lst.c utils_find.c utils_sort.c buffer.c init_piles.c push.c reverse.c rotate.c swap.c algo_sort.c sort_below_five.c sort_100_500.c clean_action.c write_fusion.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
			@rm -f $(OBJS)

fclean :	clean
			@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re .o

