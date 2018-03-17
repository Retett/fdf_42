/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:54:38 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 14:54:40 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define NOTHING 	0
# define ESC 		53
# define WIDTH 		1560
# define HEIGHT 	1240
# define ZOOM 		27
# define ZOOM_OUT 	24
# define UP 		126
# define DOWN		125
# define LEFT		123
# define RIGHT    	124

typedef	struct	s_map
{
	int			reload;
	char		*name;
	void		*mlx;
	void		*win;
	int			fd;
	int			**arr;
	int			len;
	int			line;
	int			i;
	int			z;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
}				t_map;

void			ft_error(char *str);
void			ft_free(char **str);
void			ft_fee_struct(t_map *map);
void			ft_read_file(t_map *map);
void			ft_mlx(t_map *key);
void			ft_draw(t_map *draw);
#endif
