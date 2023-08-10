/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:06:22 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/23 15:30:45 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	int	won;

	won = 0;
	get_player_position(&data->map);
	if (data->map.map_arr2[data->map.x - 1][data->map.y] == '1')
		return ;
	else if (data->map.map_arr2[data->map.x - 1][data->map.y] == 'E'
			&& count_collectable(&data->map) != 0)
		return ;
	else
	{
		printf("You moved %i times!\n", data->move_count++);
		if (data->map.map_arr2[data->map.x - 1][data->map.y] == 'E')
		{
			printf("Oh ha %s You won my game!!\n", "\U0001F631");
			won = 1;
		}
		data->map.map_arr2[data->map.x - 1][data->map.y] = 'P';
		data->map.map_arr2[data->map.x][data->map.y] = '0';
	}
	put_into_win1(data);
	put_into_win2(data);
	if (won == 1)
		mlx_loop_end(data->my_mlx);
}

void	move_down(t_data *data)
{
	int	won;

	won = 0;
	get_player_position(&data->map);
	if (data->map.map_arr2[data->map.x + 1][data->map.y] == '1')
		return ;
	else if (data->map.map_arr2[data->map.x + 1][data->map.y] == 'E'
			&& count_collectable(&data->map) != 0)
		return ;
	else
	{
		printf("You moved %i times!\n", data->move_count++);
		if (data->map.map_arr2[data->map.x + 1][data->map.y] == 'E')
		{
			printf("Oh ha %s You won my game!!\n", "\U0001F631");
			won = 1;
		}
		data->map.map_arr2[data->map.x + 1][data->map.y] = 'P';
		data->map.map_arr2[data->map.x][data->map.y] = '0';
	}
	put_into_win1(data);
	put_into_win2(data);
	if (won == 1)
		mlx_loop_end(data->my_mlx);
}

void	move_left(t_data *data)
{
	int	won;

	won = 0;
	get_player_position(&data->map);
	if (data->map.map_arr2[data->map.x][data->map.y - 1] == '1')
		return ;
	else if (data->map.map_arr2[data->map.x][data->map.y - 1] == 'E'
			&& count_collectable(&data->map) != 0)
		return ;
	else
	{
		printf("You moved %i times!\n", data->move_count++);
		if (data->map.map_arr2[data->map.x][data->map.y - 1] == 'E')
		{
			printf("Oh ha %s You won my game!!\n", "\U0001F631");
			won = 1;
		}
		data->map.map_arr2[data->map.x][data->map.y - 1] = 'P';
		data->map.map_arr2[data->map.x][data->map.y] = '0';
	}
	put_into_win1(data);
	put_into_win2(data);
	if (won == 1)
		mlx_loop_end(data->my_mlx);
}

void	move_right(t_data *data)
{
	int	won;

	won = 0;
	get_player_position(&data->map);
	if (data->map.map_arr2[data->map.x][data->map.y + 1] == '1')
		return ;
	else if (data->map.map_arr2[data->map.x][data->map.y + 1] == 'E'
			&& count_collectable(&data->map) != 0)
		return ;
	else
	{
		printf("You moved %i times!\n", data->move_count++);
		if (data->map.map_arr2[data->map.x][data->map.y + 1] == 'E')
		{
			printf("Oh ha %s You won my game!!\n", "\U0001F631");
			won = 1;
		}
		data->map.map_arr2[data->map.x][data->map.y + 1] = 'P';
		data->map.map_arr2[data->map.x][data->map.y] = '0';
	}
	put_into_win1(data);
	put_into_win2(data);
	if (won == 1)
		mlx_loop_end(data->my_mlx);
}

int	move_it_baby(int key, t_data *data)
{
	(void)data;
	if (key == 0xff52 || key == 0x0057 || key == 0x0077)
		move_up(&*data);
	if (key == 0xff54 || key == 0x0053 || key == 0x0073)
		move_down(&*data);
	if (key == 0xff51 || key == 0x0041 || key == 0x0061)
		move_left(&*data);
	if (key == 0xff53 || key == 0x0044 || key == 0x0064)
		move_right(&*data);
	if (key == 0xff1b)
		mlx_loop_end(data->my_mlx);
	return (0);
}
