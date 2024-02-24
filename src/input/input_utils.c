/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:55:31 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 02:32:35 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_left(t_game *game_object)
{
	if (game_object == NULL || game_object->sprites[PLAYER_L_INDEX] == NULL)
		return (-1);
	clear_player(game_object);
	game_object->sprites[PLAYER_L_INDEX]->instances[0].x -= TILE_PX;
	game_object->sprites[PLAYER_R_INDEX]->instances[0].x -= TILE_PX;
	game_object->sprites[PLAYER_L_INDEX]->enabled = true;
	return (0);
}

int	move_right(t_game *game_object)
{
	if (game_object == NULL || game_object->sprites[PLAYER_L_INDEX] == NULL)
		return (-1);
	clear_player(game_object);
	game_object->sprites[PLAYER_L_INDEX]->instances[0].x += TILE_PX;
	game_object->sprites[PLAYER_R_INDEX]->instances[0].x += TILE_PX;
	game_object->sprites[PLAYER_R_INDEX]->enabled = true;
	return (0);
}

int	move_up(t_game *game_object)
{
	if (game_object == NULL || game_object->sprites[PLAYER_L_INDEX] == NULL)
		return (-1);
	clear_player(game_object);
	game_object->sprites[PLAYER_L_INDEX]->instances[0].y -= TILE_PX;
	game_object->sprites[PLAYER_R_INDEX]->instances[0].y -= TILE_PX;
	game_object->sprites[PLAYER_L_INDEX]->enabled = true;
	return (0);
}

int	move_down(t_game *game_object)
{
	if (game_object == NULL || game_object->sprites[PLAYER_L_INDEX] == NULL)
		return (-1);
	clear_player(game_object);
	game_object->sprites[PLAYER_L_INDEX]->instances[0].y += TILE_PX;
	game_object->sprites[PLAYER_R_INDEX]->instances[0].y += TILE_PX;
	game_object->sprites[PLAYER_L_INDEX]->enabled = true;
	return (0);
}
