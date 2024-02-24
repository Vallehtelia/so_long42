/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:12:36 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/24 03:39:41 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
- Checks if map name is valid.
*/
void	check_map_name(char *map_name)
{
	size_t		i;
	int			j;
	char		*file_type;

	i = ft_strlen(map_name) - 4;
	j = 0;
	file_type = ".ber";
	while (map_name[i])
	{
		if (map_name[i] != file_type[j])
		{
			ft_putendl_fd("Error: Map is not .ber file.", 1);
			exit (FAIL);
		}
		i++;
		j++;
	}
}
