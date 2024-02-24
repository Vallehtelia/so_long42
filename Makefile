NAME = so_long
LIBFT = ./libft
LIBMLX = ../MLX42
MLX42LIB = ../MLX42/build/libmlx42.a -lglfw -L"/Users/vvaalant/.brew/opt/glfw/lib/"
MLXHEADER = ../MLX42/include -I $(LIBMLX)/include
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC_DIR = ./src/
COLLECTABLE_DIR = ./src/collectables/
DISPLAY_DIR = ./src/display/
EXIT_DIR = ./src/exit/
INIT_DIR = ./src/init_and_inputs/
INPUT_DIR = ./src/input/
MAP_DIR = ./src/map/
MOB_DIR = ./src/mob/
UTILS_DIR = ./src/utils/

SRC_FILES = main.c
COLLECTABLE_FILES = collectable.c
DISPLAY_FILES = display.c display_utils.c
EXIT_FILES = exit.c
INIT_FILES = init.c init_textures.c parsing.c
INPUT_FILES = handle_input.c input_utils.c inputs.c
MAP_FILES = check_map.c check_map_utils.c
MOB_FILES = player.c
UTIL_FILES = verify.c utils.c

SRC += $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC += $(addprefix $(COLLECTABLE_DIR), $(COLLECTABLE_FILES))
SRC += $(addprefix $(DISPLAY_DIR), $(DISPLAY_FILES))
SRC += $(addprefix $(EXIT_DIR), $(EXIT_FILES))
SRC += $(addprefix $(INIT_DIR), $(INIT_FILES))
SRC += $(addprefix $(INPUT_DIR), $(INPUT_FILES))
SRC += $(addprefix $(MAP_DIR), $(MAP_FILES))
SRC += $(addprefix $(MOB_DIR), $(MOB_FILES))
SRC += $(addprefix $(UTILS_DIR), $(UTIL_FILES))

OBJ = $(SRC:.c=.o)

all: $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a $(NAME)

$(LIBMLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX42LIB) -o $(NAME) -L$(LIBFT) -lft

$(LIBFT)/libft.a:
	make -C $(LIBFT)
	make bonus -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re