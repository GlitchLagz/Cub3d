NAME				:= libft.a

COMPILER			:= gcc
ARCHIVE				:= ar rc
FLAGS 				:= -Wall -Wextra -Werror

ADDSAN				:= -g -fsanitize=address

OBJECT_DIR			:= objects/
SOURCE_DIR			:= source/

SOURCE				:= $(wildcard $(SOURCE_DIR)*.c)

OBJECTS 			:= $(SOURCE:$(SOURCE_DIR)%.c=$(OBJECT_DIR)%.o)

RED     			:=\033[31m
GREEN   			:=\033[32m
YELLOW  			:=\033[33m
BLUE    			:=\033[34m

all:
					echo "$(BLUE)PLEASE STANDBY...$(GREEN)"
					make $(NAME)

$(NAME): $(OBJECT_DIR) $(OBJECTS)
					echo "$(RED)ARCHIVING LIBFT OBJECT FILES...$(GREEN)"
					$(ARCHIVE) $(NAME) $(OBJECTS)
					echo "$(RED)LIBFT ARCHIVING COMPLETE...$(GREEN)"

$(OBJECT_DIR):
					echo "$(YELLOW)CREATING OBJECT DIRECTORIES...$(GREEN)"
					mkdir -p $(OBJECT_DIR)

$(OBJECTS): $(OBJECT_DIR)%.o: $(SOURCE_DIR)%.c
							
					echo "$(BLUE)COMPILING OBJECT ($@)$(GREEN)"
					$(COMPILER) $(FLAGS) -g -o $@ -c $<

clean:		
					echo "$(YELLOW)REMOVING OBJECT FILES...$(GREEN)"
					rm -rf $(OBJECT_DIR)

fclean:	clean
					echo "$(YELLOW)REMOVING EXECUTABLE...$(GREEN)"
					rm -f $(NAME)

re: clean all

.SILENT: