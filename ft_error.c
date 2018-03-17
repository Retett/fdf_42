/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:54:15 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 14:54:16 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		ft_fee_struct(t_map *map)
{
	int i;

	i = 0;
	if (map->arr != NULL)
		while (i < map->line)
		{
			free(map->arr[i]);
			i++;
		}
	free(map);
}

void		ft_error(char *str)
{
	if (str == NULL)
		return ;
	ft_dprintf(2, "%s", str);
	exit(1);
}
