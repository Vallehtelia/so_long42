/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:53:23 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 03:02:12 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_map_solvable(t_game *game_object)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game_object->map->lines)
	{
		while (x < game_object->map->rows)
		{
			if (game_object->matrix[y][x] == COLLECTABLE \
					&& game_object->matrix[y][x] != '.')
				cleanup_and_exit(game_object, FAIL, \
								"Collectable not reachable!.");
			else if (game_object->matrix[y][x] == EXIT \
					&& game_object->matrix[y][x] != '.')
				cleanup_and_exit(game_object, FAIL, \
								"Exit not reachable!");
			x++;
		}
		x = 0;
		y++;
	}
}