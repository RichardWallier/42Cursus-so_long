#ifndef SO_LONG_H
# define SO_LONG_H
# define A_KEY 0
# define S_KEY 1 
# define D_KEY 2
# define W_KEY 13
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53

#include <fcntl.h>
#include "mlx.h"
# include "libft/libft.h"

typedef struct	s_player
{
	void	*image;
	int		ber_x;
	int		ber_y;
	int		x;
	int		y;
	int		width;
	int		height;
	int		velocity_x;
	int		velocity_y;
}				t_player;

typedef struct	s_window
{
	void	*ptr;
	int		width;
	int		height;
}				t_window;

typedef struct	s_map
{
	char 	*file;
	char	**coordenates;
	void	*wall_image;
	int		game_loop;
	int		game_frame;
	int		wall_width;
	int		wall_height;
	void	*exit_image;
	int		exit_width;
	int		exit_height;
	void	*floor_image;
	int		floor_width;
	int		floor_height;
	void	*collectable_image;
	int		collectable_count;
	int		collectable_width;
	int		collectable_height;
	void	*enemy_image;
	int		enemy_width;
	int		enemy_height;
	int		ber_x;
	int		ber_y;
}				t_map;

typedef struct	s_data
{
	void		*mlx;
	t_window	window;
	t_map		map;
	t_player	player;
}				t_data;

#endif
