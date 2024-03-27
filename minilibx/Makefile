NAME		:=libmlx.a
SRC			:= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC			+= mlx_png.c mlx_mouse.m
OBJ1		:=$(SRC:.c=.o)
OBJ			:=$(OBJ1:.m=.o)
CFLAGS		+=-O2

RED     	:=\033[31m
GREEN   	:=\033[32m
YELLOW  	:=\033[33m
BLUE    	:=\033[34m


# Add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11
# Add flag to silence deprecated declarations
CFLAGS+= -Wno-deprecated-declarations
# Add flag to silence non-prototype warnings
CFLAGS+= -Wno-strict-prototypes

all: 
						echo "$(RED)ARCHIVING MLX LIBRARY IN SILENCE...$(GREEN)"
						make $(NAME)

$(NAME):	$(OBJ)
						@ar -r $(NAME) $(OBJ)
						echo "$(RED)MLX ARCHIVING COMPLETE...$(GREEN)"

clean:
						echo "$(YELLOW)REMOVING MLX OBJECT FILES AND EXECUTABLE$(GREEN)"
						rm -f $(NAME) $(OBJ) *~
						rm -f mlx_app

re: clean all

.SILENT:
