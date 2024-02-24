/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:31:38 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 03:41:25 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
- Initializes game objects.
*/
void	init_game(t_game *game_object, char *map_name)
{
	build_matrix(game_object, map_name);
	set_start(game_object);
	set_end(game_object);
	game_object->mlx = mlx_init((TILE_PX * game_object->map->rows), \
								(TILE_PX * game_object->map->lines), \
								"so_long", true);
	init_textures(game_object);
	init_player(game_object);
}

static void	empty_file(void)
{
	ft_putendl_fd("Error: map file is empty", 1);
	exit(1);
}

/*
- Checks map and sets map strings.
*/
void	build_matrix(t_game *game_object, char *map_name)
{
	int		file;
	char	*line;
	char	*big;

	file = open(map_name, O_RDONLY);
	line = get_next_line(file);
	if (!line || line[0] == '\n')
		empty_file();
	game_object->map->lines = calc_lines(map_name);
	game_object->map->rows = calc_rows(line, '\n');
	big = ft_calloc(1, 1);
	while (line)
	{
		big = ft_strjoin(big, line);
		free(line);
		line = get_next_line(file);
	}
	free(line);
	game_object->matrix = ft_split(big, '\n');
	game_object->ref_matrix = ft_split(big, '\n');
	free(big);
	close(file);
}
