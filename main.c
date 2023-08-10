/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:32 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/27 12:01:18 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_data *data)
{
	mlx_loop_end(data->my_mlx);
	return (0);
}

int	part_of_main(t_data *data)
{
	data->mlx_win = mlx_new_window(data->my_mlx, data->map.width * 32,
			data->map.height * 32, "Yen's window");
	if (data->mlx_win == NULL)
	{
		write(2, "Error\nCouldn't create Window\n", 30); 
		ft_free(data);
		return (1);
	}
	if (texture_init(data) == 1)
	{
		write(2, "Error\nImages not found\n", 24); 
		ft_free(data);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	static t_data	data;

	data.move_count = 1;
	if (make_map(ac, av, &data.map))
	{
		if (data.map.map_array)
			ft_free_continue(&data.map);
		if (data.map.map_arr2)
			free(data.map.map_arr2);
		return (1);
	}
	data.my_mlx = mlx_init();
	if (!data.my_mlx)
		return (ft_freemap(&data.map));
	if (part_of_main(&data))
		return (1);
	put_into_win1(&data);
	put_into_win2(&data);
	mlx_hook(data.mlx_win, 17, 0, &handle_no_event, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, &move_it_baby, &data);
	mlx_loop(data.my_mlx);
	ft_free(&data);
	return (0);
}
