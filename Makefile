# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 10:33:30 by fcarranz          #+#    #+#              #
#    Updated: 2024/04/21 14:26:32 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEB=-g
OBJDIR=obj/

LIBFT_PATH=libft/
LIBFT=-Llibft -l ftprintf
INC=-Ilibft/inc
SRC=push_swap.c \
	push_swap_utils.c \
	fill_stack.c \
	movements.c \
	sort_stack.c \
	order.c
OBJS=$(SRC:%.c=$(OBJDIR)%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) Makefile push_swap.h 
	@make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

debug: $(OBJS) Makefile push_swap.h 
	make -C $(LIBFT_PATH) 
	$(CC) $(CFLAGS) $(DEB) $(OBJS) $(LIBFT) -o $@

$(OBJDIR)%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@echo "CLEANING PUSH_SWAP OBJECTS...\n"
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all
