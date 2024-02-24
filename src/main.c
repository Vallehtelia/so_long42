/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:33:06 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/23 21:34:13 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game_object;

	if (argc != 2)
	{
		return (ft_putendl_fd("so_long accepts one argument only", 2), 1);
	}
	game_object = ft_calloc(1, sizeof(t_game));
	if (!game_object)
		return (FAIL);
	game_object->map = ft_calloc(1, sizeof(t_map));
	if (!game_object->map)
		return (FAIL);
	check_files(argv[1]);
	init_game(game_object, argv[1]);
	verify(game_object);
	init_display(game_object);
	mlx_key_hook(game_object->mlx, &key_press, game_object);
	mlx_close_hook(game_object->mlx, &close_func, game_object);
	mlx_loop(game_object->mlx);
	return (SUCCESS);
}
