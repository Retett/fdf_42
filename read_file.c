/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:54:08 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 14:54:09 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_getarg(t_map *map, char **line)
{
	int j;

	j = 0;
	if ((map->arr[map->i] = malloc(sizeof(int) * map->len + 1)) == NULL)
		ft_error("Malloc error\n");
	while (line[j])
	{
		map->arr[map->i][j] = ft_atoi(line[j]);
		j++;
	}
	if (line != NULL)
		ft_free(line);
	map->i += 1;
}

void			ft_read_file(t_map *map)
{
	char		*line;
	int			i;

	i = 0;
	map->i = 0;
	while ((i = get_next_line(map->fd, &line)) > 0)
	{
		if (i == -1)
			ft_error("Error\n");
		if (ft_isdigit(line[0]) == 0 && line[0] != ' ')
		{
			if (ft_isdigit(line[1]) == 0)
				ft_error("Error\n");
		}
		ft_getarg(map, ft_strsplit(line, ' '));
		free(line);
	}
}
