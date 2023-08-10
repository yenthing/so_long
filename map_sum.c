/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:54 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/26 22:03:56 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_printer(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n\n");
}

int	check_name(char **av)
{
	int	i;

	i = 0;
	if (ft_strlen(av[1]) <= 4)
		return (1);
	while (av[1][i] && av[1][i] != 46)
		i++;
	if (!av[1][i] || !ft_strnstr(av[1] + i, ".ber", 4))
		return (1);
	if (av[1][i + 4])
		return (1);
	return (0);
}

int	fill_array(char *file_name, t_map *map)
{
	int		fd;
	int		i;
	char	*s;

	i = -1;
	map->map_arr2 = malloc(sizeof(char *) * (map->height + 1));
	map->map_array = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map_array || !map->map_arr2)
		return (write(2, "Error\nMalloc failed\n", 21), 1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nfd failed\n", 17), 1);
	while (++i < map->height)
	{
		s = get_next_line(fd);
		map->map_arr2[i] = s;
		map->map_array[i] = ft_strdup(s);
		if (!map->map_array[i] || !map->map_arr2[i])
			return (write(2, "Error\nMalloc failed\n", 21));
	}
	free (get_next_line(fd));
	map->map_array[i] = NULL;
	map->map_arr2[i] = NULL;
	close(fd);
	return (0);
}

int	count_chars(t_map *map)
{
	int	i;
	int	chars;

	i = 0;
	while (map->map_array[i])
	{
		chars = 0;
		while (map->map_array[i][chars])
		{
			if (map->map_array[i][chars] == 'P')
				map->myplayer += 1;
			if (map->map_array[i][chars] == 'E')
				map->one_exit += 1;
			if (map->map_array[i][chars] == 'C')
				map->collectable += 1;
			if (map->map_array[i][chars] == '0')
				map->floor += 1;
			chars++;
		}
		i++;
	}
	if (map->myplayer != 1 || map->one_exit != 1 || map->collectable < 1)
		return (1);
	return (0);
}

int	count_collectable(t_map *map)
{
	int	i;
	int	k;
	int	chars;

	i = 0;
	k = 0;
	while (map->map_arr2[i])
	{
		chars = 0;
		while (map->map_arr2[i][chars])
		{
			if (map->map_arr2[i][chars] == 'C')
				k++;
			chars++;
		}
		i++;
	}
	return (k);
}
