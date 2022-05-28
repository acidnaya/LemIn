PROJECT_NAME = lem-in
VISUALIZER_NAME = visu-hex

FLAGS = -Wall -Wextra -Werror

INC_DIR = ./libft/includes
OBJ_DIR = ./obj/
LIB_DIR = ./libft/

LI_SRC = bfs.c main.c queue_functions.c path_functions.c list_functions.c \
		map_set.c end_distance.c crossings.c ant_steps.c error_exit.c \
		assign_routes_to_ants.c create_queue.c
LI_OBJ = $(addprefix $(OBJ_DIR),$(LI_OBJ_NAMES))
LI_OBJ_NAMES = $(LI_SRC:.c=.o)

VIS_SRC = visual_hex.c adapt_map_coordinates.c draw_map.c draw_ants_transfer.c \
		draw_stuff.c
VIS_OBJ = $(addprefix $(OBJ_DIR),$(VIS_OBJ_NAMES))
VIS_OBJ_NAMES = $(VIS_SRC:.c=.o)

COMMON_SRC = add_link.c add_room.c delete_map_rooms.c ft_atol.c ft_lstnew_nocpy.c \
		get_next_line_single_fd.c initialize_empty_map.c process_comment.c \
		validate_and_crop_map.c find_room.c parsing.c ft_collect_mapstring.c
COMMON_OBJ = $(addprefix $(OBJ_DIR),$(COMMON_OBJ_NAMES))
COMMON_OBJ_NAMES = $(COMMON_SRC:.c=.o)

all: $(PROJECT_NAME) $(VISUALIZER_NAME)

$(PROJECT_NAME): $(LI_OBJ) $(COMMON_OBJ)
	make -C $(LIB_DIR)
	gcc $(FLAGS) -o $(PROJECT_NAME) $(COMMON_OBJ) $(LI_OBJ) -L $(LIB_DIR) -lft

$(VISUALIZER_NAME): $(VIS_OBJ) $(COMMON_OBJ)
	make -C $(LIB_DIR)
	gcc $(FLAGS) -o $(VISUALIZER_NAME) $(COMMON_OBJ) $(VIS_OBJ) -L $(LIB_DIR) -lft -L/Users/msnow-be/brew/Cellar/sdl2/2.0.9/lib -lSDL2

checker:
	gcc -o checker checker.c get_next_line_single_fd.c -L ./libft -lft

$(OBJ_DIR)%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(PROJECT_NAME)
	rm -f $(VISUALIZER_NAME)
	rm -f checker

re: fclean all
