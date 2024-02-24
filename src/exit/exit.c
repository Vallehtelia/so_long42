/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:19:43 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 03:25:06 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	clear_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	free_sprites(t_game *game_object)
{
	int	i;

	i = 0;
	while (i < SPRITE_COUNT)
	{
		if (game_object->sprites[i])
			mlx_delete_image(game_object->mlx, game_object->sprites[i]);
		i++;
	}
}

static void	terminate_all(t_game *game_object)
{
	if (game_object->ref_matrix)
		clear_split(game_object->ref_matrix);
	if (game_object->matrix)
		clear_split(game_object->matrix);
	free_sprites(game_object);
	if (game_object->mlx)
	{
		mlx_terminate(game_object->mlx);
		mlx_close_window(game_object->mlx);
	}
}

void	cleanup_and_exit(t_game *game_object, t_exit_type exit_type, \
						char *error_msg)
{
	terminate_all(game_object);
	if (exit_type == FAIL)
		ft_printf("Error: %s\n", error_msg);
	exit (exit_type);
}

void	close_func(void *param)
{
	t_game	*game_object;

	game_object = (t_game *)param;
	cleanup_and_exit(game_object, SUCCESS, "");
}
