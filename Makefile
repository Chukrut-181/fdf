# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 10:25:48 by igchurru          #+#    #+#              #
#    Updated: 2024/10/25 11:51:27 by igchurru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variable representing the name of the final executable file.
NAME = fdf
NAME_BONUS = fdf_bonus

# Compiler to be used (C compiler).
CC = cc

# Compiler flags for stricter compilation:
# -Wall: Enables all compiler's warning messages.
# -Wextra: Enables extra warning messages.
# -Werror: Treats warnings as errors to enforce stricter code.
CFLAGS = -Wall -Wextra -Werror

# Flags specific to the MLX42 library:
# -Iinclude: Specifies the directory for header files.
# -ldl: Links the dynamic loader library.
# -lglfw: Links the GLFW library for managing OpenGL context.
# -pthread: Links the POSIX threads library for multi-threading.
# -lm: Links the math library.
MLX42_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

# List of source files (without extensions).
SOURCE_FILES = main error fil_de_fer parse_map preprocess_matrix\
render_matrix render_lines bresenham get_next_line get_next_line_utils\
mlx_key_hook

# List of bonus files (without extensions).
BONUS_FILES = main_bonus error_bonus fil_de_fer_bonus parse_map_bonus preprocess_matrix_bonus\
render_matrix_bonus render_lines_bonus bresenham_bonus get_next_line_bonus get_next_line_utils_bonus\
mlx_key_hook_bonus rotate_matrix_bonus mlx_scroll_hook_bonus colors_bonus

# Directory containing the source files.
SOURCES_DIR = sources/
SOURCES_DIR_BONUS = sources_bonus/

# Directory to store the object files.
OBJECTS_DIR = objects/
OBJECTS_DIR_BONUS = objects_bonus/

# Generate a list of source files with full path and .c extension.
# $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(SOURCE_FILES)))
# Expands to: sources/main.c (this is an examle)
SOURCES = $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(SOURCE_FILES)))

# Generate a list of object files with full path and .o extension.
# $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(SOURCE_FILES)))
# Expands to: objects/main.o (again, an example)
OBJECTS = $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(SOURCE_FILES)))

SOURCES_BONUS = $(addprefix $(SOURCES_DIR_BONUS), $(addsuffix .c, $(BONUS_FILES)))
OBJECTS_BONUS = $(addprefix $(OBJECTS_DIR_BONUS), $(addsuffix .o, $(BONUS_FILES)))

# Libraries needed for linking, which includes:
# - MLX42 library, built from the MLX42/build/ directory.
# - Flags for MLX42, which provide additional libraries needed for linking.
# - Custom library "libft", which is a general-purpose library.
LIBS = MLX42/build/libmlx42.a $(MLX42_FLAGS) libft/libft.a

# Terminal color codes to display colored messages.
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
RESET = \033[0m

# "all" target: the default target that builds the libraries (libft and mlx42) and the final executable.
# Display a message indicating successful compilation of fdf executable.
# "@" before echo prevents the command from being printed to the terminal.
all: libft mlx42 $(NAME)
	@echo "$(GREEN)-> fdf compilation OK$(RESET)"

# Target to create the final executable.
# This depends on the object files being up-to-date.
# Compile and link the object files and libraries to create the executable.
$(NAME):$(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $(NAME)

# Rule to generate object files from source files.
# $(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c matches each source file with its corresponding object file.
# Create the directory for object files if it doesn't exist.
# Compile the source file into an object file with strict flags.
# $@ represents the target name (e.g., objects/main.o).
# $< represents the first prerequisite (e.g., sources/main.c).
# "-c" compiles without linking, producing object files.
$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: libft mlx42 $(NAME_BONUS)
	@echo "$(GREEN)-> fdf_bonus compilation OK$(RESET)"

# Compile the bonus executable.
$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(OBJECTS_BONUS) $(LIBS) -o $(NAME_BONUS)

# Compile object files for bonus program.
$(OBJECTS_DIR_BONUS)%.o: $(SOURCES_DIR_BONUS)%.c
	mkdir -p $(OBJECTS_DIR_BONUS)
	$(CC) $(CFLAGS) -o $@ -c $<

sanitize:
	@echo "$(YELLOW)Adding Sanitize to CFLAGS$(RESET)"
	$(eval CFLAGS=-fsanitize=address -g3)

sani: sanitize all #this rule changes CFLAGS to include sanitize and then compiles the program as usual
# Target for building the MLX42 library.
# Run make in the MLX42 build directory.
mlx42:
	make -C ./MLX42/build

# Target for building the libft library.
# Run make in the libft directory.
libft:
	make -C ./libft

# Clean target to remove object files and object directory.
# Remove the directory containing object files.
# Change directory to ./libft and execute it's own clean command.
# Display a message indicating successful clean-up of object files.
clean:
	rm -rf $(OBJECTS_DIR)
	rm -rf $(OBJECTS_DIR_BONUS)
	make clean -C ./libft
	@echo "$(YELLOW)-> All .o files removed$(RESET)"

# Full clean target, which also removes the final executable.
# Execute clean, then remove the final executable.
# Change directory to ./libft and remove libft.a
# Display a message indicating successful removal of the executable.
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f /libft/libft.a
	@echo "$(RED)-> fdf and fdf_bonus removed$(RESET)"

# "re" target to rebuild everything from scratch.
# It first runs "fclean" to remove all compiled files and then runs "all" to compile everything again.
re: fclean all

# Specify targets that aren't files, to avoid conflicts.
.PHONY: all clean fclean libft mlx42 re bonus