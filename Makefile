SOURCES	=	so_long.c

OBJECTS	=	$(SOURCES:.c=.o)

FRAMEWORK	=	-framework OpenGL -framework AppKit

CFLAGS	=	-Wall -Werror -Wextra

LIBFTPATH	=	./libft

LIBFT	=	$(LIBFTPATH)/libft.a

$(MAKE)	=	make -C

NAME = so_long

all: $(NAME)

$(LIBFT):
		$(MAKE) $(LIBFTPATH)

$(NAME):	$(LIBFT)
		gcc libft.a libmlx.a so_long.c -framework OpenGL -framework AppKit -o main
