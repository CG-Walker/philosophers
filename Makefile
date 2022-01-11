# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoncalv <cgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 01:31:00 by cgoncalv          #+#    #+#              #
#    Updated: 2021/12/14 01:31:00 by cgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS =	-Wall -Wextra -Werror
SRC		=	srcs/main.c srcs/threads.c srcs/errors.c srcs/init.c srcs/philosophers.c srcs/display.c srcs/utils_libft.c srcs/utils_philo.c
OBJ 	=	$(SRC:%.c=%.o)
NAME 	=	philo

all : $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJ)
			@echo "\n\033[32m[✓]\033[0m		[$(NAME) compiled]"

clean:
			@rm -f *.o
			@rm -f ./srcs/*.o

fclean:		clean
			@rm -f $(NAME) a.aout

re:			fclean all

exec:		all
			@echo "\033[32m[✓]\033[0m		[$(NAME) executed]\n"
			@./$(NAME)

.PHONY:		all clean fclean re exec
