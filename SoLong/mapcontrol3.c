/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:12:49 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:32:17 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int	ft_exit(t_mapinfo *map, int errno)
{
	if (errno == 1)
	{
		freemap(map);
		write(1, "Wrong map.\n", 12);
		exit(1);
	}
	if (errno == 2)
	{
		freemap(map);
		write(1, "Wrong map.\n", 12);
		exit(1);
	}
	if (errno == 3)
	{
		write(1, "Dont do this man.\n", 19);
		exit(1);
	}
	if (errno == 4)
	{
		write(1, "Please man please dont.\n", 25);
		exit(1);
	}
	exit(1);
	return (0);
}

void	freemap(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	getplayer(t_mapinfo *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->px = j;
				map->py = i;
			}
			j++;
		}
		i++;
	}
}

void	wallcheck(t_mapinfo *map)
{
	int	j;
	int	i;

	j = 0;
	i = map->row - 1;
	while (map->map[0][j] && map->map[map->row - 1][j])
	{
		if (map->map[0][j] != '1' || map->map[map->row - 1][j] != '1')
		{
			ft_exit(map, 2);
		}
		j++;
	}
	while (i > 0)
	{
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
		{
			ft_exit(map, 2);
		}
		i--;
	}
}
