/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:30 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:17:11 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_settings(t_mapinfo *arg)
{
	int	x;
	int	y;
	int	j;
	int	i;

	i = 0;
	y = 0;
	while (i < arg->row)
	{
		j = 0;
		x = 0;
		while (j < arg->column)
		{
			ft_img_put_me_down(arg, arg->map[i][j], x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
}

void	ft_rplc(t_mapinfo *map, int x, int y, int k)
{
	if (k == 13 && map->map[y - 1][x] != '1')
	{
		map->map[y - 1][x] = 'P';
		map->py--;
		map->vi_current = 13;
	}
	if (k == 1 && map->map[y + 1][x] != '1')
	{
		map->map[y + 1][x] = 'P';
		map->py++;
		map->vi_current = 1;
	}
	if (k == 0 && map->map[y][x - 1] != '1')
	{
		map->map[y][x - 1] = 'P';
		map->px--;
		map->vi_current = 0;
	}
	if (k == 2 && map->map[y][x + 1] != '1')
	{
		map->map[y][x + 1] = 'P';
		map->px++;
		map->vi_current = 2;
	}
	map->map[y][x] = '0';
}

int	ft_check_ext(t_mapinfo *arg, int k)
{
	if (k == 13 && arg->map[arg->py - 1][arg->px] == 'E')
		return (1);
	if (k == 0 && arg->map[arg->py][arg->px - 1] == 'E')
		return (1);
	if (k == 1 && arg->map[arg->py + 1][arg->px] == 'E')
		return (1);
	if (k == 2 && arg->map[arg->py][arg->px + 1] == 'E')
		return (1);
	return (0);
}

void	control1(t_mapinfo *map)
{
	char	*line;
	int		a;

	openmap(map);
	line = get_next_line(map->fd);
	if (!line)
	{
		free(line);
		ft_exit(map, 3);
	}
	a = ft_l_strlen(line);
	free(line);
	close(map->fd);
	if (a < 2)
	{
		ft_exit(map, 4);
	}
}
