/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:17:48 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 02:02:00 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_collectable(t_game *game)
{
	size_t	i;
	int		cur_x;
	int		cur_y;

	i = 0;
	cur_x = game->current_x;
	cur_y = game->current_y;
	if (game->ref_matrix[cur_y][cur_x] == COLLECTABLE)
	{
		game->map->collectables++;
		game->ref_matrix[cur_y][cur_x] = GROUND;
		while (i < game->sprites[COLLECTABLE_INDEX]->count)
		{
			if (game->sprites[COLLECTABLE_INDEX]->instances[i].x \
					== cur_x * TILE_PX \
					&& game->sprites[COLLECTABLE_INDEX]->instances[i].y \
					== cur_y * TILE_PX)
				game->sprites[COLLECTABLE_INDEX]->instances[i].enabled = false;
			i++;
		}
	}
	if (game->map->collectables == game->map->total_collectables \
			&& game->map->collectables > 0)
		game->sprites[EXIT_INDEX]->enabled = true;
}

void	check_win(t_game *game_object)
{
	int	cur_x;
	int	cur_y;

	cur_x = game_object->current_x;
	cur_y = game_object->current_y;
	if (game_object->map->collectables == game_object->map->total_collectables \
			&& game_object->map->collectables > 0 \
			&& cur_y == game_object->end_y && cur_x == game_object->end_x)
	{
		ft_printf("Well done, you finished with %i moves!\n", \
				game_object->moves);
		cleanup_and_exit(game_object, SUCCESS, "");
	}
}
