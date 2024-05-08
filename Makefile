# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 10:33:30 by fcarranz          #+#    #+#              #
#    Updated: 2024/05/08 11:17:23 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g
OBJDIR=obj/

LIB=$(LIBFT_PATH)libftprintf.a
LIBFT_PATH=libft/
LIBFT=-Llibft -lftprintf
INC=-Ilibft/inc

SRC=push_swap.c \
	push_swap_utils.c \
	fill_stack.c \
	movements.c \
	movements_aux.c \
	sort_stack.c \
	push_item.c \
	push_item_aux.c \
	order.c
OBJS=$(SRC:%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)
	@echo "===== READY ====="

$(NAME): $(LIB) $(OBJS) Makefile push_swap.h 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJDIR)%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIB): $(LIBFT_PATH)Makefile
	@echo "LIBFT COMPILING..."
	@make -C $(LIBFT_PATH) > /dev/null

clean:
	@make clean -C $(LIBFT_PATH) > /dev/null
	@rm -rf $(OBJDIR)
	@echo "===== OBJECTS CLEANED ====="

fclean: clean
	@make fclean -C $(LIBFT_PATH) > /dev/null
	@rm -f $(NAME)

re: fclean all
