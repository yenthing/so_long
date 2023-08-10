/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:47:49 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/26 21:58:29 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_arr2[y][x] == 'P')
			{
				map->x = y;
				map->y = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	virus(t_map *map, int x, int y)
{
	map->map_array[x][y] = 'F';
	if (map->map_array[x - 1][y] == '0' || map->map_array[x - 1][y] == 'C')
		virus(map, x - 1, y);
	if (map->map_array[x][y - 1] == '0' || map->map_array[x][y - 1] == 'C')
		virus(map, x, y - 1);
	if (map->map_array[x + 1][y] == '0' || map->map_array[x + 1][y] == 'C')
		virus(map, x + 1, y);
	if (map->map_array[x][y + 1] == '0' || map->map_array[x][y + 1] == 'C')
		virus(map, x, y + 1);
	return (0);
}

int	map_validity(t_map *map)
{
	get_player_position(map);
	if (map->x == 0 || map->y == 0)
		return (1);
	if (virus(map, map->x, map->y))
		return (1);
	if (check_left_thing(map, 0))
		return (1);
	return (0);
}

int	make_map(int ac, char **av, t_map *map)
{
	if (ac != 2)
	{
		write(2, "Invalid ammount of arguments\n", 30);
		return (1);
	}
	if (check_name(av))
	{
		write(2, "Error\nMap's Name is not valid\n", 31);
		return (1);
	}
	if (count_array(av[1], map) != 0)
		return (1);
	if (fill_array(av[1], map) != 0)
		return (1);
	if (check_wall(map) || count_chars(map) || map_validity(map))
	{
		write(2, "Error\nMap is not valid\n", 24);
		return (1);
	}
	return (0);
}
