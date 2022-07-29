# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:57:51 by aarribas          #+#    #+#              #
#    Updated: 2022/07/30 00:29:55 by aarribas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#main
NAME			=	push_swap
CC				= 	gcc $(FLAGS)
FLAGS			=	-Wall -Werror -Wextra -g
RM				=	rm -rf
OBJS			=	$(PUSH_SWAP_SRC:.c=.o)

#files
LIBFT_DIR		=	libft/
LIBFT			=	$(addprefix $(LIBFT_DIR),libft.a)

CHECKER_DIR		=	bonus/
CHECKER			=	$(addprefix $(CHECKER_DIR),checker)

MANDATORY_SRCS	=	operations.c operations_1.c operations_2.c operations_3.c \
					push_swap.c stacks_fill.c small_sort.c calculations.c \
					big_sort.c
					
MANDATORY_DIR	=	mandatory/
MANDATORY		=	$(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))
OBJ_M			=	$(MANDATORY:.c=.o)

INCLUDES_SRCS	=	push_swap.h
INCLUDES_DIR	=	includes/
INCLUDES		=	$(addprefix $(INCLUDES_DIR),$(INCLUDES_SRCS))


all	:	$(NAME) $(CHECKER)

$(NAME):			$(OBJ_M) $(LIBFT) $(INCLUDES) Makefile
					$(CC) $(OBJ_M) $(LIBFT) -o $(NAME)

%.o: %.c $(INCLUDES) $(LIBFT)
		$(CC) -c $< -o $@

$(LIBFT):	libft/Makefile
			make -C libft/

$(CHECKER):	bonus/Makefile
			make -C bonus/
			cp -rf bonus/checker ./

clean: 
					$(RM) $(NAME) $(OBJ_M)
					$(RM) checker

fclean: clean
		$(RM) $(NAME) $(OBJ_M)
		make fclean -C libft/
		make fclean -C bonus/

re : fclean all

.PHONY: all clean fclean re