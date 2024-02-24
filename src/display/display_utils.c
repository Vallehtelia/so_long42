/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:02:15 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 02:01:16 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_wall(t_game *game_object)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game_object->map->lines)
	{
		while (x < game_object->map->rows)
		{
			if (game_object->ref_matrix[y][x] == WALL)
				mlx_image_to_window(game_object->mlx, \
									game_object->sprites[WALL_INDEX], \
									x * TILE_PX, y * TILE_PX);
			x++;
		}
		x = 0;
		y++;
	}
}

void	display_ground(t_game *game_object)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game_object->map->lines)
	{
		while (x < game_object->map->rows)
		{
			if (game_object->ref_matrix[y][x] != WALL)
				mlx_image_to_window(game_object->mlx, \
									game_object->sprites[GROUND_INDEX], \
									x * TILE_PX, y * TILE_PX);
			x++;
		}
		x = 0;
		y++;
	}
}

void	display_exit(t_game *game_object)
{
	mlx_image_to_window(game_object->mlx, game_object->sprites[EXIT_INDEX], \
						game_object->end_x * TILE_PX, \
						game_object->end_y * TILE_PX);
	game_object->sprites[EXIT_INDEX]->enabled = false;
}

void	display_collectable(t_game *game_object)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game_object->map->lines)
	{
		while (x < game_object->map->rows)
		{
			if (game_object->ref_matrix[y][x] == COLLECTABLE)
			{
				mlx_image_to_window(game_object->mlx, \
								game_object->sprites[COLLECTABLE_INDEX], \
								x * TILE_PX, y * TILE_PX);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	display_player(t_game *game_object)
{
	mlx_image_to_window(game_object->mlx, \
						game_object->sprites[PLAYER_L_INDEX], \
						game_object->current_x * TILE_PX, \
						game_object->current_y * TILE_PX);
	mlx_image_to_window(game_object->mlx, \
						game_object->sprites[PLAYER_R_INDEX], \
						game_object->current_x * TILE_PX, \
						game_object->current_y * TILE_PX);
	clear_player(game_object);
	game_object->sprites[PLAYER_R_INDEX]->enabled = true;
}
