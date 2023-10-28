/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:12:13 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:32:13 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	getmap(t_mapinfo *map)
{
	int		x;
	int		y;
	char	*line;

	openmap(map);
	y = 0;
	if (map->isvalid == 1)
	{
		while (y < map->row)
		{
			x = 0;
			line = get_next_line(map->fd);
			if (!line)
				ft_exit(map, 2);
			while (x < map->column)
			{
				map->map[y][x] = line[x];
				x++;
			}
			map->map[y][x] = '\0';
			free(line);
			y++;
		}
	}
	close(map->fd);
}

void	gettmp(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		map->tmpmap[i] = ft_strdup2(map->map[i]);
		i++;
	}
	map->tmpmap[i] = NULL;
}

void	check_rect(t_mapinfo *arg)
{
	int	i;
	int	j;
	int	l_len;
	int	h_len;

	l_len = ft_l_strlen(arg->map[0]);
	h_len = arg->row;
	i = 0;
	while (i < h_len)
	{
		j = 0;
		while (j < l_len && arg->map[i][j])
		{
			if ((j == 0 || j == (l_len - 1) || i == 0 || i == h_len - 1)
				&& arg->map[i][j] != '1')
				ft_exit(arg, 2);
			j++;
		}
		if (ft_l_strlen(arg->map[i]) != l_len)
			ft_exit(arg, 2);
		i++;
	}
}

void	ft_validmap_check(t_mapinfo *map, int y, int x)
{
	char	*p;

	p = &map->tmpmap[y][x];
	if (*p == 'E')
		map->c_e = 0;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			map->c_c--;
		*p = '.';
		if (map->tmpmap[y][x + 1] != '1' &&
			map->tmpmap[y][x + 1] != '.')
			ft_validmap_check(map, y, x + 1);
		if (map->tmpmap[y][x - 1] != '1' &&
			map->tmpmap[y][x - 1] != '.')
			ft_validmap_check(map, y, x - 1);
		if (map->tmpmap[y - 1][x] != '1' &&
			map->tmpmap[y - 1][x] != '.')
			ft_validmap_check(map, y - 1, x);
		if (map->tmpmap[y + 1][x] != '1' &&
			map->tmpmap[y + 1][x] != '.')
			ft_validmap_check(map, y + 1, x);
	}
}
