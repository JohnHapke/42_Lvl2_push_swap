# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 08:52:58 by jhapke            #+#    #+#              #
#    Updated: 2025/04/23 09:17:42 by jhapke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wextra -Werror -Wall

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft

SRC = $(wildcard $(SRC_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/algo/*.c) \
		$(wildcard $(SRC_DIR)/core/*.c) \
		$(wildcard $(SRC_DIR)/ops/*.c) \
		$(wildcard $(SRC_DIR)/utils/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC = -I$(INC_DIR) -I$(LIBFT_DIR)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)
		mkdir -p $(OBJ_DIR)/algo
		mkdir -p $(OBJ_DIR)/core
		mkdir -p $(OBJ_DIR)/ops
		mkdir -p $(OBJ_DIR)/utils

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
		make -C $(LIBFT_DIR) clean
		rm -rf $(OBJ_DIR)

fclean: clean
		make -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re