/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:07 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:02:21 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup2(char *a)
{
	int		i;
	char	*b;

	i = 0;
	while (a[i])
		i++;
	b = malloc(sizeof(char) * (i + 1));
	b[i] = '\0';
	i--;
	while (i >= 0)
	{
		b[i] = a[i];
		i--;
	}
	return (b);
}

void	allocatemap(t_mapinfo *array)
{
	int	i;

	i = 0;
	array->map = malloc(sizeof(char *) * (array->row + 1));
	array->map[array->row] = NULL;
	while (i < array->row)
	{
		array->map[i] = malloc(sizeof(char) * array->column + 1);
		i++;
	}
	i = 0;
	array->tmpmap = malloc(sizeof(char *) * (array->row + 1));
	array->tmpmap[array->row] = NULL;
}

void	openmap(t_mapinfo *map)
{
	char	*line;

	map->fd = open(map->mapname, O_RDONLY);
	line = get_next_line(map->fd);
	if (!line)
	{
		free(line);
		close(map->fd);
		ft_exit(map, 3);
	}
	if (map->fd < 0)
	{
		free(line);
		close(map->fd);
		ft_exit(map, 4);
	}
	free(line);
	close(map->fd);
	map->fd = open(map->mapname, O_RDONLY);
}
