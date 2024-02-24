/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:07:45 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 02:52:31 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_shape_invalid(t_game *game_object);
static bool	check_walls_invalid(t_game *game_object);
static bool	check_collectables_invalid(t_game *game_object);

static void	flood_fill(t_game *game_object, int x, int y)
{
	if ((x < 0 || x > game_object->map->rows - 1) || (y < 0 \
		|| y > game_object->map->lines - 1) \
		|| game_object->matrix[y][x] == '.' \
		|| game_object->matrix[y][x] == WALL)
		return ;
	if (game_object->matrix[y][x] == COLLECTABLE)
		game_object->map->total_collectables++;
	if (game_object->matrix[y][x] == PLAYER)
		game_object->map->num_of_players++;
	if (game_object->matrix[y][x] == EXIT)
		game_object->map->num_of_exits++;
	game_object->matrix[y][x] = '.';
	flood_fill(game_object, x - 1, y);
	flood_fill(game_object, x + 1, y);
	flood_fill(game_object, x, y + 1);
	flood_fill(game_object, x, y - 1);
}

void	verify(t_game *game_object)
{
	bool	shape;
	bool	walls;
	bool	collectables;

	flood_fill(game_object, game_object->current_x, game_object->current_y);
	is_map_solvable(game_object);
	if (game_object->map->num_of_exits != 1)
		cleanup_and_exit(game_object, FAIL, "Map should contain 1 exit.");
	if (game_object->map->num_of_players != 1)
		cleanup_and_exit(game_object, FAIL, "Map should contain 1 player.");
	shape = check_shape_invalid(game_object);
	if (shape)
		cleanup_and_exit(game_object, FAIL, "Map size invald.");
	walls = check_walls_invalid(game_object);
	if (walls)
		cleanup_and_exit(game_object, FAIL, "Map walls invalid.");
	collectables = check_collectables_invalid(game_object);
	if (collectables)
		cleanup_and_exit(game_object, FAIL, \
						"Collectable invalid or non-existent");
}

static bool	check_shape_invalid(t_game *game_object)
{
	int			i;
	size_t		n;
	size_t		base_len;

	i = 0;
	n = 0;
	base_len = ft_strlen(game_object->matrix[i]);
	while (i < game_object->map->lines)
	{
		n = ft_strlen(game_object->matrix[i]);
		if (n != base_len)
			return (true);
		i++;
	}
	return (false);
}

static bool	check_walls_invalid(t_game *game_object)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game_object->map->lines)
	{
		while (x < game_object->map->rows)
		{
			if (game_object->ref_matrix[y][x] != WALL && (y == 0 || x == 0
					|| x == game_object->map->rows - 1 \
					|| y == game_object->map->lines - 1))
			{
				return (true);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (false);
}

static bool	check_collectables_invalid(t_game *game_object)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game_object->map->lines)
	{
		while (i < game_object->map->rows)
		{
			if (game_object->ref_matrix[j][i] == COLLECTABLE)
			{
				if (game_object->matrix[j][i] != '.')
					return (true);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (game_object->map->total_collectables < 1)
		return (true);
	else
		return (false);
}
