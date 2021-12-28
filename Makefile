# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 10:42:09 by mlecuyer          #+#    #+#              #
#    Updated: 2021/09/02 16:24:11 by mlecuyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	clang -Wall -Wextra -Werror

INC 	= -I./includes

SRCS	=	main.c \
			tools/parsing.c \
			oper/pa.c \
			oper/pb.c \
			oper/swap.c \
			oper/reverse_rotate.c \
			oper/rotate.c \
			oper/rr.c \
			oper/rrr.c \
			oper/ss.c \
			tools/list_utils.c \
			sorting/little_sorting.c \
			sorting/big_sorting.c \
			tools/list_utils_bis.c \
			tools/push_atoi.c \
			sorting/big_sorting_b.c \
			tools/tools.c \
			sorting/little_sorting_extra.c \


FIL = 		$(addprefix srcs/, $(SRCS))

OBJ = 		$(FIL:.c=.o)

BIN = 		$(addsuffix .o, $(SRCS))

.c.o:
			@${CC} ${INC} -c $< -o ${<:.c=.o}

all:		$(NAME)

${NAME}:	$(OBJ)
				make -s -C ./libft
				$(CC) $(INC) $(OBJ) -Llibft -lft -o $(NAME)


clean:
			make -s clean -C ./libft
			rm -rf $(OBJ)
			
			
fclean:		clean
				make -s fclean -C ./libft
				rm -f $(NAME)
			
				

re:			fclean all

.PHONY:		all clean fclean re
