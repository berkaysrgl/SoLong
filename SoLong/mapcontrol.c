/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:12:35 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:32:02 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

void	getrow(t_mapinfo *map)
{
	int		tmprow;
	char	*line;

	tmprow = 0;
	openmap(map);
	line = get_next_line(map->fd);
	if (!line)
	{
		free(line);
		ft_exit(map, 4);
	}
	while (line)
	{
		free(line);
		tmprow++;
		line = get_next_line(map->fd);
	}
	if (tmprow < 3)
		ft_exit(map, 3);
	free(line);
	map->row = tmprow;
	close(map->fd);
}

void	getcolumn(t_mapinfo *map)
{
	char	*line;
	int		i;

	i = 1;
	openmap(map);
	line = get_next_line(map->fd);
	if (!line)
		ft_exit(map, 4);
	map->column = ft_strlen(line) - 1;
	free(line);
	while (i < map->row)
	{
		line = get_next_line(map->fd);
		if (!line)
			ft_exit(map, 3);
		if (map->column != ft_strlen(line) - 1 && i != map->row - 1)
			ft_exit(map, 3);
		else if (map->column != ft_strlen(line) && i == map->row - 1)
			ft_exit(map, 3);
		i++;
		free(line);
	}
	close(map->fd);
}

void	checkagain(t_mapinfo *map)

{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y != map->row - 1)
	{
		while (x != map->column - 1)
		{
			if (map->map[y][x] == 'C')
			{
				map->c_c += 1;
			}
			x++;
		}
		y++;
		x = 1;
	}
}

void	start(t_mapinfo *map)
{
	control1(map);
	openmap(map);
	structinit(map);
	getrow(map);
	getcolumn(map);
	allocatemap(map);
	getmap(map);
	gettmp(map);
	wallcheck(map);
	check_diff(map);
	checkchar(map);
	validchar(map);
	getplayer(map);
	ft_validmap_check(map, map->py, map->px);
	checkvalid(map);
	checkagain(map);
}
