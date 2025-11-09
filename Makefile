# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 14:44:24 by wilisson          #+#    #+#              #
#    Updated: 2025/11/09 17:13:22 by wilisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -flto 
LIBFT_DIR = libft/
MLX42_DIR = mlx42/
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git
INCLUDES = -I include/ -I $(LIBFT_DIR) -I $(MLX42_DIR)include/

SRC =	main.c \
		sources/fractals_math.c \
		sources/atof.c\
		sources/hooks.c \
		sources/init_utils.c \
		sources/render_utils.c \
		sources/rendering.c 

OBJ = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)libft.a
MLX42_LIB = $(MLX42_DIR)build/libmlx42.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	LIBS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit
endif
ifeq ($(UNAME_S),Linux)
	LIBS = -lglfw -lGL -ldl -lm -lpthread
endif

all: clone_mlx42 $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42_LIB) -o $(NAME) $(LIBS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX42_LIB):
	cmake -B $(MLX42_DIR)build -S $(MLX42_DIR)
	cmake --build $(MLX42_DIR)build

clone_mlx42:
	@if [ ! -d "$(MLX42_DIR).git" ]; then \
		echo "Cloning MLX42 library..."; \
		git clone $(MLX42_REPO) $(MLX42_DIR); \
	else \
		echo "MLX42 already cloned."; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ) $(MLX42_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) $(MLX42_DIR)

re: fclean all

.PHONY: all bonus clean fclean re clone_mlx42