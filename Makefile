# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:57:51 by aarribas          #+#    #+#              #
#    Updated: 2022/10/17 18:23:38 by aarribas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#main
NAME			=	push_swap
CC				= 	gcc $(FLAGS)
FLAGS			=	-Wall -Werror -Wextra #-g -fsanitize=address
RM				=	rm -rf
OBJS			=	$(PUSH_SWAP_SRC:.c=.o)

#files
LIBFT_DIR		=	libft/
LIBFT			=	$(addprefix $(LIBFT_DIR),libft.a)


MANDATORY_SRCS	=	operations.c operations_1.c operations_2.c operations_3.c \
					push_swap.c stacks_fill.c small_sort.c calculations.c \
					big_sort.c
					
MANDATORY_DIR	=	mandatory/
MANDATORY		=	$(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))
OBJ_M			=	$(MANDATORY:.c=.o)

INCLUDES_SRCS	=	push_swap.h
INCLUDES_DIR	=	includes/
INCLUDES		=	$(addprefix $(INCLUDES_DIR),$(INCLUDES_SRCS))

CHECKER_DIR		=	bonus/
CHECKER			=	checker

BONUS_SRCS		=	checker.c ft_atoi.c ft_split.c ft_strjoin.c ft_strlen.c \
					ft_strcmp.c operations.c operations_1.c instructions.c \
					utils.c ft_bzero.c ft_calloc.c ft_memset.c \
					
BONUS_DIR		=	bonus/srcs/
BONUS			=	$(addprefix $(BONUS_DIR), $(BONUS_SRCS))
OBJ_B			=	$(BONUS:.c=.o)

INCLU_SRC_BO	=	checker.h
INCLU_DIR_BO	=	bonus/includes/
INCLUDES_BO		=	$(addprefix $(INCLU_BO),$(INCLU_DIR_BO))


all	:	$(NAME)

$(NAME):			$(OBJ_M) $(LIBFT) $(INCLUDES) Makefile
					$(CC) $(OBJ_M) $(LIBFT) -o $(NAME)

%.o: %.c $(INCLUDES) $(LIBFT) 
		$(CC) -c $< -o $@

$(LIBFT):	libft/Makefile
			make -C libft/

bonus:		$(CHECKER)

$(CHECKER):	$(OBJ_B) $(INCLUDES_BO) Makefile
			$(CC) $(OBJ_B) -o $(CHECKER)

clean: 
					$(RM) $(NAME) 
					$(RM) $(CHECKER)

fclean: clean
		$(RM) $(NAME) $(OBJ_M)
		make fclean -C $(LIBFT_DIR)
		$(RM) $(CHECKER) $(OBJ_B)

re : fclean all

.PHONY: all clean fclean re bonus