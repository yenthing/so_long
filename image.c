/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:23 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/27 12:04:40 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	texture_init(t_data *data)
{
	int	i;
	int	t;

	i = 32;
	t = 32;
	data->image.player = mlx_xpm_file_to_image(data->my_mlx,
			"images/player.xpm", &i, &t);
	data->image.myexit = mlx_xpm_file_to_image(data->my_mlx,
			"images/myexit.xpm", &i, &t);
	data->image.collect = mlx_xpm_file_to_image(data->my_mlx,
			"images/collect.xpm", &i, &t);
	data->image.wall = mlx_xpm_file_to_image(data->my_mlx,
			"images/wall.xpm", &i, &t);
	data->image.floor = mlx_xpm_file_to_image(data->my_mlx,
			"images/floor.xpm", &i, &t);
	if (data->image.player == NULL || data->image.myexit == NULL
		|| data->image.collect == NULL)
		return (1);
	if (data->image.wall == NULL || data->image.floor == NULL)
		return (1);
	return (0);
}

int	ft_image(t_data *data, void *img, char *path)
{
	int	i;
	int	t;

	i = 32;
	t = 32;
	img = mlx_xpm_file_to_image(data->my_mlx, path, &i, &t);
	if (img == 0)
		exit(0);
	return (0);
}

void	put_into_win1(t_data *hey)
{
	int	w;
	int	h;

	h = -1;
	while (hey->map.map_arr2[++h])
	{
		w = -1;
		while (hey->map.map_arr2[h][++w])
		{
			if (hey->map.map_arr2[h][w] == '1')
				mlx_put_image_to_window(hey->my_mlx, hey->mlx_win,
					hey->image.wall, (w * 32), (h * 32));
			else if (hey->map.map_arr2[h][w] == 'C')
				mlx_put_image_to_window(hey->my_mlx, hey->mlx_win,
					hey->image.collect, (w * 32), (h * 32));
			else if (hey->map.map_arr2[h][w] == 'P')
				mlx_put_image_to_window(hey->my_mlx, hey->mlx_win,
					hey->image.player, (w * 32), (h * 32));
		}
	}
}

void	put_into_win2(t_data *hey)
{
	int	w;
	int	h;

	h = -1;
	while (hey->map.map_arr2[++h])
	{
		w = -1;
		while (hey->map.map_arr2[h][++w])
		{
			if (hey->map.map_arr2[h][w] == 'E')
				mlx_put_image_to_window(hey->my_mlx, hey->mlx_win,
					hey->image.myexit, (w * 32), (h * 32));
			else if (hey->map.map_arr2[h][w] == '0')
				mlx_put_image_to_window(hey->my_mlx, hey->mlx_win,
					hey->image.floor, (w * 32), (h * 32));
		}
	}
}
