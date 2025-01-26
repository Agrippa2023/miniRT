# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 16:36:14 by aouichou          #+#    #+#              #
#    Updated: 2023/08/17 11:10:34 by aouichou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS_DIR = Srcs
OBJS_DIR = Objs
INCS_DIR = -I Includes -I Libs/libft/ -I Libs/minilibx-linux/
LIBFT_DIR = Libs/libft
MLX_DIR = Libs/minilibx-linux

SRCS = $(shell find $(SRCS_DIR) -name "*.c")
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror $(INCS_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR) -L minilibx-linux -lmlx -lXext -lX11 -lm -lbsd 
LFLAGS = -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lXext -lX11 \
		 -lm -lpthread -lmlx_Linux -lbsd

all: $(OBJ_D) $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)
	@echo "\033[32m$(NAME) created successfully !\033[0m"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "\033[31m$(NAME) objects deleted successfully !\033[0m"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) deleted successfully !\033[0m"

re: fclean all

.PHONY: all clean fclean re