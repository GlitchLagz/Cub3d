NAME						:=		cub3D
		
COMPILER					:=		gcc
OPTIMISE					:=      #-Ofast -flto -march=native -msse4.2
FLAGS						:=		-Wextra -Werror -Wall $(OPTIMISE)

ADDSAN						:=		#-fsanitize=address -g

LIBFT_DIR					:=		libft/
LIBFT_A						:=		$(LIBFT_DIR)libft.a
		
MLX_DIR						:=		minilibx/
MLX_A						:=		$(MLX_DIR)libmlx.a
		
LINK_MLX					:=		-lmlx
LINK_MLX_DIR				:=		-Lminilibx
		
LINK_OPENGL_FW				:=		-framework OpenGL
LINK_APPKIT_FW				:=		-framework AppKit
		
OBJECT_DIR					:=		objects/
SOURCE_DIR					:=		source/
CHECK_DIR					:=		check/
MAP_DIR						:=		map/
INIT_DIR					:=		init/
PARSE_DIR					:=		parse/
RENDER_DIR					:=		render/
INIT_SOURCE_DIR				:=		$(SOURCE_DIR)$(INIT_DIR)
RENDER_SOURCE_DIR			:=		$(SOURCE_DIR)$(RENDER_DIR)
CHECK_SOURCE_DIR			:=		$(SOURCE_DIR)$(CHECK_DIR)
PARSE_SOURCE_DIR			:=		$(SOURCE_DIR)$(PARSE_DIR)
INIT_OBJ_DIR				:=		$(OBJECT_DIR)$(INIT_DIR)
RENDER_OBJ_DIR				:=		$(OBJECT_DIR)$(RENDER_DIR)
CHECK_OBJECT_DIR			:=		$(OBJECT_DIR)$(CHECK_DIR)
PARSE_OBJECT_DIR			:=		$(OBJECT_DIR)$(PARSE_DIR)
		

INIT_SOURCE					:=	$(SOURCE_DIR)init/exit.c \
$(SOURCE_DIR)init/free.c \
$(SOURCE_DIR)init/init.c \
$(SOURCE_DIR)init/main.c

RENDER_SOURCE				:=		$(RENDER_SOURCE_DIR)better_mlx.c \
$(SOURCE_DIR)render/cast_collision.c\
$(SOURCE_DIR)render/controls.c \
$(SOURCE_DIR)render/controls_two.c \
$(SOURCE_DIR)render/draw_functions.c \
$(SOURCE_DIR)render/raycast-horizontal.c \
$(SOURCE_DIR)render/raycast-setconditions.c  \
$(SOURCE_DIR)render/raycast-vertical.c \
$(SOURCE_DIR)render/render-utils.c \
$(SOURCE_DIR)render/render.c
		
PARSE_SOURCE				:=		$(SOURCE_DIR)parse/parse.c \
$(SOURCE_DIR)parse/rgb.c

CHECK_SOURCE				:=		$(SOURCE_DIR)check/check_parameters.c \
$(SOURCE_DIR)check/player.c \
$(SOURCE_DIR)check/print.c
		
SOURCE						:=		\
									$(INIT_SOURCE) \
									$(PARSE_SOURCE) \
									$(CHECK_SOURCE) \
									$(RENDER_SOURCE)
		
OBJECTS						:=		$(SOURCE:$(SOURCE_DIR)%.c=$(OBJECT_DIR)%.o)
		
LINK						:=		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_A) $(MLX_A) \
									$(LINK_MLX_DIR) $(LINK_MLX) $(LINK_OPENGL_FW) $(LINK_APPKIT_FW) $(ADDSAN) -lz
		
RED     					:=\033[31m
GREEN   					:=\033[32m
YELLOW  					:=\033[33m
BLUE    					:=\033[34m

all:
							echo "$(BLUE)PLEASE STANDBY...$(GREEN)"
							make $(NAME)

test:
							./$(NAME) $(MAP_DIR)map_minimalist_test.cub

lobby: all
							./$(NAME) $(MAP_DIR)map_herason_lobby.cub

dungeon: all
							./$(NAME) $(MAP_DIR)map_herason_dungeon.cub

room_4: all
							./$(NAME) $(MAP_DIR)map_herason_room_4.cub

library: all
							./$(NAME) $(MAP_DIR)map_herason_library.cub

$(NAME): $(OBJECT_DIR) $(OBJECTS) $(MLX_A) $(LIBFT_A)
							echo "$(GREEN)CREATING EXECUTABLE...$(GREEN)"
							$(LINK)

$(OBJECTS): $(OBJECT_DIR)%.o: $(SOURCE_DIR)%.c 
							
							echo "$(BLUE)COMPILING OBJECT ($@)$(GREEN)"
							$(COMPILER) $(FLAGS) -g -o $@ -c $<

$(OBJECT_DIR):
							echo "CREATING OBJECT DIRECTORIES...$(GREEN)"
							mkdir -p $(INIT_OBJ_DIR)
							mkdir -p $(CHECK_OBJECT_DIR)
							mkdir -p $(PARSE_OBJECT_DIR)
							mkdir -p $(RENDER_OBJ_DIR)

clean:
							echo "$(YELLOW)REMOVING OBJECT FILES...$(GREEN)"
							rm -rf $(OBJECT_DIR)
							rm -rf $(NAME).dSYM

fclean: clean
							echo "$(RED)REMOVING EXECUTABLE...$(GREEN)"
							make fclean -C $(LIBFT_DIR)
							make clean -C $(MLX_DIR)
							rm -f $(NAME)
$(MLX_A):
	echo "$(BLUE)RECOMPILING MLX LIBRARY FOR ARCHITECTURE CHANGE...$(GREEN)"
	make -C $(MLX_DIR)

$(LIBFT_A):
	echo "$(BLUE)RECOMPILING LIBFT LIBRARY FOR ARCHITECTURE CHANGE...$(GREEN)"
	make -C $(LIBFT_DIR)

libs: $(LIBFT_A) $(MLX_A)
	echo "$(BLUE)READY TO MAKE EXECUTABLE...$(GREEN)"


project_libs_clean: clean
							echo "$(YELLOW)CLEANING OBJECT FILES FROM LIBS...$(GREEN)"
							make clean -C $(LIBFT_DIR)
							make clean -C $(MLX_DIR)
							
re: libs fclean all

.PHONY: clean fclean libs re test lobby room_4 library
#.SILENT: # Remove for verbosity


