/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:48:05 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 02:02:23 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	w_press(t_game *game_object)
{
	bool	bounds;

	bounds = check_move_invalid(game_object, game_object->current_y - 1, \
								game_object->current_x);
	if (!bounds)
	{
		move_up(game_object);
		game_object->moves++;
		game_object->current_y--;
		check_collectable(game_object);
		ft_printf("moves: %i\n", game_object->moves);
	}
}

void	a_press(t_game *game_object)
{
	bool	bounds;

	bounds = check_move_invalid(game_object, game_object->current_y, \
								game_object->current_x - 1);
	if (!bounds)
	{
		move_left(game_object);
		game_object->moves++;
		game_object->current_x--;
		check_collectable(game_object);
		check_win(game_object);
		ft_printf("moves: %i\n", game_object->moves);
	}
}

void	s_press(t_game *game_object)
{
	bool	bounds;

	bounds = check_move_invalid(game_object, game_object->current_y + 1, \
								game_object->current_x);
	if (!bounds)
	{
		move_down(game_object);
		game_object->moves++;
		game_object->current_y++;
		check_collectable(game_object);
		ft_printf("moves: %i\n", game_object->moves);
	}
}

void	d_press(t_game *game_object)
{
	bool	bounds;

	bounds = check_move_invalid(game_object, game_object->current_y, \
								game_object->current_x + 1);
	if (!bounds)
	{
		move_right(game_object);
		game_object->moves++;
		game_object->current_x++;
		check_collectable(game_object);
		ft_printf("moves: %i\n", game_object->moves);
	}
}

bool	check_move_invalid(t_game *game_object, int y, int x)
{
	if (game_object->ref_matrix[y][x] == WALL)
		return (true);
	return (false);
}
