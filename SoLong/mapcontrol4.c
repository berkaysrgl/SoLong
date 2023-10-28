/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:01 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:32:54 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	structinit(t_mapinfo *map)
{
	map->row = 0;
	map->isvalid = 1;
	map->c_c = 0;
	map->c_e = 0;
	map->c_p = 0;
	map->px = 0;
	map->py = 0;
	map->count = 0;
}

void	checkchar(t_mapinfo *map)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y != map->row - 1)
	{
		while (x != map->column - 1)
		{
			if (map->map[y][x] == 'P')
				map->c_p += 1;
			else if (map->map[y][x] == 'C')
				map->c_c += 1;
			else if (map->map[y][x] == 'E')
				map->c_e += 1;
			x++;
		}
		y += 1;
		x = 1;
	}
}

void	validchar(t_mapinfo *map)
{
	if (map->c_c < 1)
	{
		ft_exit(map, 1);
	}
	if (map->c_p != 1)
	{
		ft_exit(map, 1);
	}
	if (map->c_e != 1)
	{
		ft_exit(map, 1);
	}
}
