# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:57:51 by aarribas          #+#    #+#              #
#    Updated: 2022/07/30 10:19:27 by aarribas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#main
NAME			=	checker
CC				= 	gcc $(FLAGS)
FLAGS			=	-Wall -Werror -Wextra -g
RM				=	rm -rf
OBJS			=	$(CHECKER_SRC:.c=.o)

MANDATORY_SRCS	=	checker.c ft_atoi.c ft_split.c ft_strjoin.c ft_strlen.c \
					ft_strcmp.c operations.c operations_1.c instructions.c \
					utils.c ft_bzero.c ft_calloc.c ft_memset.c \
					
MANDATORY_DIR	=	srcs/
MANDATORY		=	$(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))
OBJ_M			=	$(MANDATORY:.c=.o)

INCLUDES_SRCS	=	checker.h
INCLUDES_DIR	=	includes/
INCLUDES		=	$(addprefix $(INCLUDES_DIR),$(INCLUDES_SRCS))


all	:	$(NAME) 

$(NAME):			$(OBJ_M) $(INCLUDES) Makefile
					$(CC) $(OBJ_M) -o $(NAME)

%.o: %.c $(INCLUDES)
		$(CC) -c $< -o $@

clean: 
					$(RM) $(NAME) $(OBJ_M)

fclean: clean
		$(RM) $(NAME) $(OBJ_M)

re : fclean all

.PHONY: all clean fclean re