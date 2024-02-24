/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:17:03 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 02:26:53 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
- Calculates lines.
*/
int	calc_lines(char *map_name)
{
	int		i;
	int		l;
	int		fd;
	char	buf[1];

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	i = 0;
	l = 0;
	while (read(fd, buf, 1) > 0)
	{
		if (buf[0] == '\n')
			i++;
		l++;
	}
	if (i > 0)
		i++;
	close(fd);
	return (i);
}

/*
- Calculates rows.
*/
int	calc_rows(char *line, int c)
{
	int	i;

	if (!*line)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
- Sets player location.
*/
void	set_start(t_game *game_object)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game_object->map->lines)
	{
		while (x < game_object->map->rows)
		{
			if (game_object->ref_matrix[y][x] == PLAYER)
			{
				game_object->current_y = y;
				game_object->current_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

/*
- Sets exit location.
*/
void	set_end(t_game *game_object)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game_object->map->lines)
	{
		while (i < game_object->map->rows)
		{
			if (game_object->ref_matrix[j][i] == EXIT)
			{
				game_object->end_y = j;
				game_object->end_x = i;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
