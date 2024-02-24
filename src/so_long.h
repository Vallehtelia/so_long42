/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:33:34 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 03:01:30 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

/* Game */
# define WIDTH 1000
# define HEIGHT 1000
# define FILENAME_SIZE 69
# define LEFT -1
# define RIGHT 1
# define UP -1
# define DOWN 1

/* Map and sprites */
# define WALL_PATH "./assets/world/wall.png"
# define GROUND_PATH "./assets/world/floor.png"
# define EXIT_PATH "./assets/world/exit.png"
# define TILE_PX 64
# define MAX_LINES 250
# define SPRITE_COUNT 6
# define WALL_INDEX 0
# define GROUND_INDEX 1
# define EXIT_INDEX 2
# define COLLECTABLE_INDEX 3
# define PLAYER_L_INDEX 4
# define PLAYER_R_INDEX 5

/* Player */
# define PLAYER_PATH_R "./assets/player/electrician_right.png"
# define PLAYER_PATH_L "./assets/player/electrician_left.png"
# define PLAYER_HEIGHT_PX 64
# define PLAYER_WIDTH_PX 64

/* Collectables */
# define COLLECTABLE_PATH "./assets/collectables/coin0.png"
# define COLLECTABLE_HEIGHT_PX 64
# define COLLECTABLE_WIDTH_PX 64

typedef enum e_tile_type
{
	WALL = '1',
	GROUND = '0',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tile_type;

typedef enum e_exit_type
{
	SUCCESS,
	FAIL,
}	t_exit_type;

typedef struct s_map
{
	int			lines;
	int			rows;
	int			collectables;
	int			total_collectables;
	int			num_of_players;
	int			num_of_exits;
}	t_map;


typedef struct s_game
{
	t_map		*map;
	mlx_image_t	*sprites[SPRITE_COUNT];
	void		*mlx;
	void		*win;
	char		*addr;
	char		**matrix;
	char		**ref_matrix;
	int			img_pxl;
	int			moves;
	int			current_x;
	int			current_y;
	int			end_x;
	int			end_y;
}				t_game;

int		main(int argc, char **argv);

/* Errors and exits */
void	cleanup_and_exit(t_game *game_object, t_exit_type exit_type, \
						char *error_msg);
void	close_func(void *param);

/* initialize */
void	init_game(t_game *game_object, char *map_name);
void	init_textures(t_game *game_object);
void	build_matrix(t_game	*game_object, char *map_name);
int		calc_lines(char *map_name);
int		calc_rows(char *line, int c);
void	set_start(t_game *game_object);
void	set_end(t_game *game_object);
void	init_player(t_game *game_object);
void	init_display(t_game *game_object);

/* Display */
void	display_wall(t_game *game_object);
void	display_ground(t_game *game_object);
void	display_exit(t_game *game_object);
void	display_collectable(t_game *game_object);
void	display_player(t_game *game_object);

/* Collectables and win check */
void	check_collectable(t_game *game);
void	check_win(t_game *game_object);

/* Inputs */
void	clear_player(t_game *game_object);
void	key_press(mlx_key_data_t keydata, void *param);
void	w_press(t_game *game_object);
void	a_press(t_game *game_object);
void	s_press(t_game *game_object);
void	d_press(t_game *game_object);
int		move_up(t_game *game_object);
int		move_down(t_game *game_object);
int		move_left(t_game *game_object);
int		move_right(t_game *game_object);
bool	check_move_invalid(t_game *game_object, int y, int x);

/* Map */
void	check_files(char *map_name);
void	check_map_name(char *map_name);
void	verify(t_game *game_object);
void	is_map_solvable(t_game *game_object);

/* Free */
void	free_game_memory(t_game *game_object);


#endif
