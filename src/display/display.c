/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:49 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/23 16:02:00 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_display(t_game *game_object)
{
	display_wall(game_object);
	display_ground(game_object);
	display_collectable(game_object);
	display_exit(game_object);
	display_player(game_object);
}
