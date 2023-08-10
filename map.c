/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:06:16 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/26 21:18:20 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_height(char *file, t_map *map_info)
{
	int		fd;
	char	*line;

	map_info->height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nMap is unable to open\n", 29);
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		map_info->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}

int	finsih_gnl(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	count_width(char *file, t_map *map_info)
{
	int		fd;
	int		len_first_line;
	char	*line;
	int		i;

	i = 0;
	map_info->width = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	len_first_line = ft_strlen(line);
	while (line)
	{
		map_info->width = ft_strlen(line);
		if (len_first_line != map_info->width && i != map_info->height - 1)
			return (finsih_gnl(fd, line));
		if (i == (map_info->height - 1) && ((ft_strlen(line)
					+ 1) != (unsigned long)len_first_line))
			return (finsih_gnl(fd, line));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (0);
}

int	check_wall(t_map *map)
{
	int	i;
	int	chars;

	i = 0;
	while (map->map_array[i])
	{
		chars = 0;
		while (map->map_array[i][chars])
		{
			if ((i == 0 || i == map->height - 1 || chars == 0
					|| chars == map->width - 1)
				&& map->map_array[i][chars] != '\n')
			{
				if (map->map_array[i][chars] != '1')
					return (1);
			}
			chars++;
		}
		i++;
	}
	return (0);
}

int	count_array(char *file_name, t_map *map_info)
{
	if (count_height(file_name, map_info))
		return (1);
	if (count_width(file_name, map_info) == 1)
	{
		write(2, "Error\nLines are not the same length\n", 37);
		return (1);
	}
	return (0);
}
