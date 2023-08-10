/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:05:16 by ynguyen           #+#    #+#             */
/*   Updated: 2023/07/26 20:08:50 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

# define UP 0x0077
# define DOWN 0x0073
# define LEFT 0x0061
# define RIGHT 0x0064

typedef struct s_img
{
	void			*collect;
	void			*wall;
	void			*player;
	void			*myexit;
	void			*floor;
}					t_img;

typedef struct s_map
{
	char			**map_arr2;
	char			**map_array;
	int				width;
	int				height;
	int				myplayer;
	int				collectable;
	int				one_exit;
	int				floor;
	int				x;
	int				y;
}					t_map;

typedef struct s_data
{
	void			*my_mlx;
	void			*mlx_win;
	struct s_img	image;
	struct s_map	map;
	int				move_count;

}					t_data;

//free.c
int					ft_freemap(t_map *map);
int					ft_free_continue(t_map *map);
void				ft_free(t_data *data);

//image.c
int					texture_init(t_data *data);
int					ft_image(t_data *data, void *img, char *path);
void				put_into_win1(t_data *hey);
void				put_into_win2(t_data *hey);

//map_sum.c
void				map_printer(char **map);
int					check_name(char **av);
int					fill_array(char *file_name, t_map *map);
int					count_chars(t_map *map);
int					count_collectable(t_map *map);

//map.c
int					check_wall(t_map *map);
int					count_array(char *file_name, t_map *map_info);

//main.c
int					ft_freemap(t_map *map);

//map_check.c
int					check_path_valid3(t_map *map);
int					check_left_thing(t_map *map, int ex);

//movement.c
int					move_it_baby(int key, t_data *data);

//utils.c
void				get_player_position(t_map *map);
int					virus(t_map *map, int x, int y);
int					map_validity(t_map *map);
int					make_map(int ac, char **av, t_map *map);

#endif
