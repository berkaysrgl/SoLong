/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:09:32 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 10:46:29 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_move_count(t_mapinfo *map)
{
	char	*count;
	int		i;

	count = ft_itoa(map->count);
	i = ft_strlen(count);
	write(1, count, i);
	write(1, "\n", 1);
	mlx_string_put(map->mlx_ptr, map->mlx_win, 50, 20, 0x00BDFF, count);
	free(count);
}

int	ft_check_wall(t_mapinfo *arg, int k)
{
	if (k == 13 && arg->map[arg->py - 1][arg->px] == '1')
		return (1);
	if (k == 0 && arg->map[arg->py][arg->px - 1] == '1')
		return (1);
	if (k == 1 && arg->map[arg->py + 1][arg->px] == '1')
		return (1);
	if (k == 2 && arg->map[arg->py][arg->px + 1] == '1')
		return (1);
	return (0);
}
