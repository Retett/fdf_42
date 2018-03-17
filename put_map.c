/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:54:33 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 14:54:34 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	fix_cord(int *pix, int *tab, int *y0, int *x0)
{
	if (pix[1] > -tab[0])
	{
		pix[0] -= tab[2];
		(*x0) += tab[1];
	}
	if (pix[1] < tab[2])
	{
		pix[0] += tab[0];
		(*y0) += tab[3];
	}
}

static void		draw_line(t_map *map, int *tabxy)
{
	int		x0;
	int		y0;
	int		tab[5];
	int		fix[2];

	x0 = tabxy[0];
	y0 = tabxy[1];
	tab[0] = abs(tabxy[2] - x0);
	tab[1] = x0 < tabxy[2] ? 1 : -1;
	tab[2] = abs(tabxy[3] - y0);
	tab[3] = y0 < tabxy[3] ? 1 : -1;
	fix[0] = (tab[0] > tab[2] ? tab[0] : -tab[2]) / 2;
	while (y0 != tabxy[3] || x0 != tabxy[2])
	{
		mlx_pixel_put(map->mlx, map->win, x0, y0, 0x00FFFFFF);
		fix[1] = fix[0];
		fix_cord(fix, tab, &y0, &x0);
	}
}

static void		reload_map(t_map *map)
{
	if (map->reload == 1)
	{
		map->z = -5;
		map->dx = (WIDTH - 200) / 2;
		map->dy = 150;
		map->sx = ((WIDTH) / 2) / (map->len + 5);
		map->sy = ((HEIGHT) / 2) / (map->line + 5);
	}
	map->reload = 0;
}

static void		draw_lines(t_map *map, int x, int y)
{
	int		tabxy[4];

	tabxy[0] = map->dx + (x - y);
	tabxy[1] = map->dy + map->arr[y / map->sy][x / map->sx] * map->z
		+ x + y;
	if (x / map->sx < map->len - 1 && y / map->sy < map->line)
	{
		tabxy[2] = map->dx + ((x + map->sx) - y);
		tabxy[3] = map->dy + map->arr[y / map->sy][x / map->sx + 1] * map->z +
		(x + map->sx) + y;
		draw_line(map, tabxy);
	}
	if (y / map->sy < map->line - 1 && x / map->sx < map->len)
	{
		tabxy[2] = map->dx + (x - (y + map->sy));
		tabxy[3] = map->dy + map->arr[y / map->sy + 1][x / map->sx] * map->z +
		x + (y + map->sy);
		draw_line(map, tabxy);
	}
}

void			ft_draw(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	reload_map(map);
	while (x / map->sx < map->len || y / map->sy < map->line - 1)
	{
		if (x / map->sx == map->len)
		{
			x = 0;
			y += map->sy;
		}
		draw_lines(map, x, y);
		x += map->sx;
	}
}
