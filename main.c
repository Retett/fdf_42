/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:53:59 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 14:54:00 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			struct_init(t_map *map)
{
	map->reload = 1;
	map->name = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map->fd = 0;
	map->arr = NULL;
	map->len = 0;
	map->line = 0;
	map->i = 0;
	map->z = 0;
	map->dx = 0;
	map->dy = 0;
	map->sx = 0;
	map->sy = 0;
}

static void			check_error(char *line, t_map *map)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
		i++;
	if (map->line == NOTHING)
	{
		map->len = i;
	}
	if (i != map->len)
		ft_error("Error\n");
	ft_free(split);
}

static void			map_init(t_map *map)
{
	char	*line;
	int		i;
	int		ret;

	i = 0;
	map->line = 0;
	while ((ret = get_next_line(map->fd, &line)) > 0)
	{
		check_error(line, map);
		free(line);
		i++;
	}
	map->line = i;
	if ((map->arr = (int**)malloc(sizeof(int*) * (i))) == NULL)
		ft_error("Malloc error\n");
}

int					main(int ac, char **av)
{
	t_map	*map;

	if ((map = (t_map*)malloc(sizeof(t_map) * 1)) == NULL)
		ft_error("Malloc error\n");
	struct_init(map);
	if (ac != 2)
		ft_error("usage: ./fdf map/file\n");
	map->name = av[1];
	map->fd = open(map->name, O_DIRECTORY);
	if (map->fd >= 0)
		ft_error("Wrong map!\nusage: ./fdf map/file\n");
	map->fd = open(map->name, O_RDONLY);
	if (map->fd <= 0)
		ft_error("Wrong map!\nusage: ./fdf map/file\n");
	else
		map_init(map);
	close(map->fd);
	map->fd = open(map->name, O_RDONLY);
	ft_read_file(map);
	ft_mlx(map);
	ft_fee_struct(map);
	return (0);
}
