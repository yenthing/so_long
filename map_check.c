/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:48:48 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/23 16:11:04 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path_valid3(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->height)
	{
		y = -1;
		while (++y < map->width)
		{
			if (map->map_array[x][y] == 'E')
			{
				if (map->map_array[x - 1][y] != 'F' && map->map_array[x
					+ 1][y] != 'F' && map->map_array[x][y - 1] != 'F'
					&& map->map_array[x][y + 1] != 'F')
					return (1);
			}
		}
	}
	return (0);
}

int	check_left_thing(t_map *map, int ex)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->height)
	{
		y = -1;
		while (++y < map->width)
		{
			if (map->map_array[x][y] == 'C')
				return (1);
			if (map->map_array[x][y] == 'E')
			{
				if (check_path_valid3(map))
					return (1);
				ex++;
			}
			if (map->map_array[x][y] != 'F' && map->map_array[x][y] != '1'
				&& map->map_array[x][y] != '0' && map->map_array[x][y] != 'E')
				return (1);
		}
	}
	if (ex != 1)
		return (1);
	return (0);
}
