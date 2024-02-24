/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:15:05 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 00:54:06 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_wall(t_game *game_object)
{
	mlx_texture_t	*texture;
	mlx_image_t		*wall;

	texture = mlx_load_png(WALL_PATH);
	if (!texture)
		cleanup_and_exit(game_object, FAIL, "Failed to load wall texture.");
	wall = mlx_texture_to_image(game_object->mlx, texture);
	if (!wall)
		cleanup_and_exit(game_object, FAIL, "Failed to load texture to image.");
	game_object->sprites[WALL_INDEX] = wall;
	mlx_resize_image(wall, TILE_PX, TILE_PX);
	mlx_delete_texture(texture);
}

static void	init_ground(t_game *game_object)
{
	mlx_texture_t	*texture;
	mlx_image_t		*ground;

	texture = mlx_load_png(GROUND_PATH);
	if (!texture)
		cleanup_and_exit(game_object, FAIL, "Failed to load ground texture.");
	ground = mlx_texture_to_image(game_object->mlx, texture);
	if (!ground)
		cleanup_and_exit(game_object, FAIL, "Failed to load texture to image.");
	mlx_resize_image(ground, TILE_PX, TILE_PX);
	game_object->sprites[GROUND_INDEX] = ground;
	mlx_delete_texture(texture);
}

static void	init_exit(t_game *game_object)
{
	mlx_texture_t	*texture;
	mlx_image_t		*exit;

	texture = mlx_load_png(EXIT_PATH);
	if (!texture)
		cleanup_and_exit(game_object, FAIL, "Failed to load exit texture.");
	exit = mlx_texture_to_image(game_object->mlx, texture);
	if (!exit)
		cleanup_and_exit(game_object, FAIL, "Failed to load texture to image.");
	mlx_resize_image(exit, TILE_PX, TILE_PX);
	game_object->sprites[EXIT_INDEX] = exit;
	mlx_delete_texture(texture);
}

static void	init_collectables(t_game *game_object)
{
	mlx_texture_t	*texture;
	mlx_image_t		*collectable;

	texture = mlx_load_png(COLLECTABLE_PATH);
	if (!texture)
		cleanup_and_exit(game_object, FAIL, \
						"Failed to load collectable texture.");
	collectable = mlx_texture_to_image(game_object->mlx, texture);
	if (!collectable)
		cleanup_and_exit(game_object, FAIL, "Failed to load texture to image.");
	mlx_resize_image(collectable, COLLECTABLE_WIDTH_PX, COLLECTABLE_HEIGHT_PX);
	game_object->sprites[COLLECTABLE_INDEX] = collectable;
	mlx_delete_texture(texture);
}

/*
- Initializes wall, ground, exit and collectable objects.
*/
void	init_textures(t_game *game_object)
{
	init_wall(game_object);
	init_ground(game_object);
	init_exit(game_object);
	init_collectables(game_object);
}
