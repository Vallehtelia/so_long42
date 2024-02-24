/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:08:33 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 03:39:36 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
- Checks if map opens and file name is valid.
*/
void	check_files(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error: Failed to open map file.", 2);
		exit (FAIL);
	}
	check_map_name(map_name);
	close(fd);
}
