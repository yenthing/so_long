/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:45:08 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/27 12:02:54 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_freemap(t_map *map)
{
	int	x;

	x = 0;
	while (map->map_arr2[x])
	{
		free(map->map_arr2[x]);
		free(map->map_array[x++]);
	}
	free(map->map_arr2);
	free(map->map_array);
	return (1);
}

int	ft_free_continue(t_map *map)
{
	int	x;

	x = 0;
	while (map->map_arr2 && map->map_arr2[x])
	{
		if (map->map_arr2[x])
			free(map->map_arr2[x]);
		if (map->map_array[x])
			free(map->map_array[x]);
		x++;
	}
	if (map->map_arr2)
	{
		free(map->map_arr2);
		map->map_arr2 = NULL;
	}
	if (map->map_array)
	{
		free(map->map_array);
		map->map_array = NULL;
	}
	return (1);
}

void	ft_free(t_data *data)
{
	if (data->image.myexit)
		mlx_destroy_image(data->my_mlx, data->image.myexit);
	if (data->image.floor)
		mlx_destroy_image(data->my_mlx, data->image.floor);
	if (data->image.player)
		mlx_destroy_image(data->my_mlx, data->image.player);
	if (data->image.collect)
		mlx_destroy_image(data->my_mlx, data->image.collect);
	if (data->image.wall)
		mlx_destroy_image(data->my_mlx, data->image.wall);
	if (data->mlx_win)
		mlx_destroy_window(data->my_mlx, data->mlx_win);
	if (data->my_mlx)
	{
		mlx_destroy_display(data->my_mlx);
		free(data->my_mlx);
	}
	ft_free_continue(&data->map);
}
