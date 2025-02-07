# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 10:25:48 by igchurru          #+#    #+#              #
#    Updated: 2025/02/07 11:25:35 by igchurru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_BONUS = fdf_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX42_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

SOURCE_FILES = main error fil_de_fer parse_map preprocess_matrix\
render_matrix render_lines bresenham get_next_line get_next_line_utils\
mlx_key_hook

BONUS_FILES = main_bonus error_bonus fil_de_fer_bonus parse_map_bonus preprocess_matrix_bonus\
render_matrix_bonus render_lines_bonus bresenham_bonus get_next_line_bonus get_next_line_utils_bonus\
mlx_key_hook_bonus rotate_matrix_bonus mlx_scroll_hook_bonus colors_bonus toggle_projection_bonus

SOURCES_DIR = sources/
SOURCES_DIR_BONUS = sources_bonus/

OBJECTS_DIR = objects/
OBJECTS_DIR_BONUS = objects_bonus/

SOURCES = $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(SOURCE_FILES)))

OBJECTS = $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(SOURCE_FILES)))

SOURCES_BONUS = $(addprefix $(SOURCES_DIR_BONUS), $(addsuffix .c, $(BONUS_FILES)))
OBJECTS_BONUS = $(addprefix $(OBJECTS_DIR_BONUS), $(addsuffix .o, $(BONUS_FILES)))

LIBS = MLX42/build/libmlx42.a $(MLX42_FLAGS) libft/libft.a

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
RESET = \033[0m

all: update_submodules libft mlx42 $(NAME)
	@echo "$(GREEN)-> fdf compilation OK$(RESET)"

update_submodules:
	@git submodule update --init --recursive
	@echo "$(YELLOW)-> Submodules updated$(RESET)"

$(NAME):$(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBS) -o $(NAME)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus: update_submodules libft mlx42 $(NAME_BONUS)
	@echo "$(GREEN)-> fdf_bonus compilation OK$(RESET)"

$(NAME_BONUS): $(OBJECTS_BONUS)
	@$(CC) $(OBJECTS_BONUS) $(LIBS) -o $(NAME_BONUS)

$(OBJECTS_DIR_BONUS)%.o: $(SOURCES_DIR_BONUS)%.c
	@mkdir -p $(OBJECTS_DIR_BONUS)
	@$(CC) $(CFLAGS) -o $@ -c $<

sanitize:
	@echo "$(YELLOW)Adding Sanitize to CFLAGS$(RESET)"
	@$(eval CFLAGS=-fsanitize=address -g3)

sani: fclean sanitize all 

mlx42:
	if [ ! -d "MLX42/build" ]; then \
		mkdir -p MLX42/build && cd MLX42/build && cmake ..; \
	fi
	make -C MLX42/build

libft:
	make -C ./libft

clean:
	@rm -rf $(OBJECTS_DIR)
	@rm -rf $(OBJECTS_DIR_BONUS)
	@make clean -C ./libft
	@rm -rf MLX42/build
	@echo "$(YELLOW)-> All .o files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C ./libft
	@echo "$(RED)-> fdf and fdf_bonus removed$(RESET)"

re: fclean all

.PHONY: all clean fclean libft mlx42 re bonus update_submodules sani sanitize