/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:18:44 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/01 14:18:45 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				ft_move(t_map *map, int key)
{
	mlx_clear_window(map->mlx, map->win);
	if (key == 1)
		map->dx -= 15;
	else if (key == 2)
		map->dx += 15;
	else if (key == 3)
		map->dy += 15;
	else if (key == 4)
		map->dy -= 15;
	else if (key == 7 && map->sx * 2 <= 700 && map->sy * 2 <= 700)
	{
		map->sx *= 2;
		map->sy *= 2;
		map->z *= 2;
		map->dy -= 150;
	}
	else if (key == 6 && map->sx * 0.5 >= 1 && map->sy * 0.5 >= 1 &&
	(-map->z * 0.5 >= 1 || map->z * 0.5 >= 1))
	{
		map->sx *= 0.5;
		map->sy *= 0.5;
		map->z *= 0.5;
		map->dy += 150;
	}
}

static int				keyboard(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		ft_fee_struct(map);
		exit(1);
	}
	else if (keycode == UP)
		ft_move(map, 4);
	else if (keycode == DOWN)
		ft_move(map, 3);
	else if (keycode == LEFT)
		ft_move(map, 1);
	else if (keycode == RIGHT)
		ft_move(map, 2);
	else if (keycode == ZOOM)
		ft_move(map, 6);
	else if (keycode == ZOOM_OUT)
		ft_move(map, 7);
	else
		return (0);
	ft_draw(map);
	return (1);
}

void					ft_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, map->name);
	ft_draw(map);
	mlx_key_hook(map->win, keyboard, map);
	mlx_loop(map->mlx);
}
