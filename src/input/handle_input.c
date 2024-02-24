/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:00:29 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 00:45:07 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game_object;

	game_object = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		cleanup_and_exit(game_object, SUCCESS, "");
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT \
			|| keydata.action == MLX_RELEASE))
		w_press(game_object);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT \
			|| keydata.action == MLX_RELEASE))
		a_press(game_object);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT \
			|| keydata.action == MLX_RELEASE))
		s_press(game_object);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT \
			|| keydata.action == MLX_RELEASE))
		d_press(game_object);
}

void	clear_player(t_game *game_object)
{
	int	i;

	i = PLAYER_L_INDEX;
	while (i < 6)
	{
		game_object->sprites[i]->enabled = false;
		i++;
	}
}
