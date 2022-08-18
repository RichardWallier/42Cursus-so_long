SOURCES	=	so_long.c keyboard_event.c framework.c 
SOURCES	+=	parse.c so_long_utils.c map_checker.c
SOURCES	+=	error_handling.c

OBJECTS			=	$(SOURCES:.c=.o)

SOURCES_BONUS	=	so_long_bonus.c keyboard_event_bonus.c framework_bonus.c 
SOURCES_BONUS	+=	game_loop_bonus.c parse_bonus.c so_long_utils_bonus.c
SOURCES_BONUS	+=	error_handling_bonus.c map_checker_bonus.c

OBJECTS_BONUS	=	$(SOURCES_BONUS:.c=.o)

FRAMEWORK		=	-framework OpenGL -framework AppKit

CFLAGS			=	-Wall -Werror -Wextra

LIBFTPATH		=	./libft

LIBFT			=	$(LIBFTPATH)/libft.a

MLXPATH			=	./minilibx

MLX				=	$(MLXPATH)/libmlx.a

MAKE			=	make -C

NAME			=	so_long

NAME_BONUS		=	so_long_bonus

RM				=	rm -f

.c.o:	
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
		$(MAKE) $(LIBFTPATH)

$(MLX):
		$(MAKE) $(MLXPATH)

$(NAME):	$(OBJECTS) $(LIBFT) $(MLX)
		$(CC) $(LIBFT) $(MLX) $(OBJECTS) $(FRAMEWORK) -o $(NAME)

$(NAME_BONUS):	$(OBJECTS_BONUS) $(LIBFT) $(MLX)
		$(CC) $(LIBFT) $(MLX) $(OBJECTS_BONUS) $(FRAMEWORK) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)
	$(MAKE) $(MLXPATH) clean
	$(MAKE) $(LIBFTPATH) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) $(LIBFTPATH) clean
	$(RM) $(MLX)

re: fclean all
