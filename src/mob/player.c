/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:01:09 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 00:53:30 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_player_r(t_game *game_object)
{
	mlx_texture_t	*texture;
	mlx_image_t		*player;

	texture = mlx_load_png(PLAYER_PATH_R);
	if (!texture)
		cleanup_and_exit(game_object, FAIL, "Failed to load player_r texture.");
	player = mlx_texture_to_image(game_object->mlx, texture);
	if (!player)
		cleanup_and_exit(game_object, FAIL, "Failed to load texture to image.");
	mlx_resize_image(player, PLAYER_WIDTH_PX, PLAYER_HEIGHT_PX);
	game_object->sprites[PLAYER_R_INDEX] = player;
	mlx_delete_texture(texture);
}

static void	init_player_l(t_game *game_object)
{
	mlx_texture_t	*texture;
	mlx_image_t		*player;

	texture = mlx_load_png(PLAYER_PATH_L);
	if (!texture)
		cleanup_and_exit(game_object, FAIL, "Failed to load player_l texture.");
	player = mlx_texture_to_image(game_object->mlx, texture);
	if (!player)
		cleanup_and_exit(game_object, FAIL, "Failed to load texture to image.");
	mlx_resize_image(player, PLAYER_WIDTH_PX, PLAYER_HEIGHT_PX);
	game_object->sprites[PLAYER_L_INDEX] = player;
	mlx_delete_texture(texture);
}

/*
- Initializes player objects.
*/
void	init_player(t_game *game_object)
{
	init_player_r(game_object);
	init_player_l(game_object);
}
