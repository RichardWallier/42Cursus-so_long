SOURCES	=	so_long.c

OBJECTS	=	$(SOURCES:.c=.o)

FRAMEWORK	=	-framework OpenGL -framework AppKit

CFLAGS	=	-Wall -Werror -Wextra

LIBFTPATH	=	./libft

LIBFT	=	$(LIBFTPATH)/libft.a

MLXPATH	=	./minilibx_opengl_20191021

MLX	=	$(MLXPATH)/libmlx.a

MAKE	=	make -C

NAME = so_long

RM = rm -f

.c.o:	
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(LIBFT):
		@$(MAKE) $(LIBFTPATH)

$(MLX):
		@$(MAKE) $(MLXPATH)

$(NAME):	$(LIBFT) $(MLX) $(OBJECTS)
		$(CC) $(LIBFT) $(MLX) $(OBJECTS) $(FRAMEWORK) -o $(NAME)

clean:
	$(RM) $(OBJECTS)
	$(MAKE) $(MLXPATH) clean
	$(MAKE) $(LIBFTPATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBFTPATH) clean
	$(RM) $(MLX)

re: fclean all
