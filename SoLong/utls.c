/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:27 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 10:05:34 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_if_win(t_mapinfo *map, int k)
{
	if (k == 13 && map->map[map->py - 1][map->px] == 'E' && map->c_c == 0)
	{
		map->count++;
		put_move_count(map);
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		write(1, "Tebrikler oyunu basariyla bitirdiniz!\n", 39);
		exit(1);
	}
	if (k == 0 && map->map[map->py][map->px - 1] == 'E' && map->c_c == 0)
	{
		map->count++;
		put_move_count(map);
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		write(1, "Tebrikler oyunu basariyla bitirdiniz!\n", 39);
		exit(1);
	}
}

void	ft_if_win2(t_mapinfo *map, int k)
{
	if (k == 1 && map->map[map->py + 1][map->px] == 'E' && map->c_c == 0)
	{
		map->count++;
		put_move_count(map);
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		write(1, "Tebrikler oyunu basariyla bitirdiniz!\n", 39);
		exit(1);
	}
	if (k == 2 && map->map[map->py][map->px + 1] == 'E' && map->c_c == 0)
	{
		map->count++;
		put_move_count(map);
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		write(1, "Tebrikler oyunu basariyla bitirdiniz!\n", 39);
		exit(1);
	}
}

void	ft_check_c(t_mapinfo *arg, int k)
{
	if (k == 13 && arg->map[arg->py - 1][arg->px] == 'C')
	{
		arg->c_c--;
	}
	if (k == 0 && arg->map[arg->py][arg->px - 1] == 'C')
	{
		arg->c_c--;
	}
	if (k == 1 && arg->map[arg->py + 1][arg->px] == 'C')
	{
		arg->c_c--;
	}
	if (k == 2 && arg->map[arg->py][arg->px + 1] == 'C')
	{
		arg->c_c--;
	}
}

int	ft_set_win(int keycode, t_mapinfo *map)
{
	int		k;
	char	*str_write;

	k = keycode;
	if (k == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		exit(1);
	}
	ft_if_win(map, k);
	ft_if_win2(map, k);
	if ((k == 13 || k == 0 || k == 1 || k == 2)
		&& !ft_check_ext(map, k) && !ft_check_wall(map, k))
	{
		ft_check_c(map, k);
		ft_rplc(map, map->px, map->py, keycode);
		mlx_clear_window(map->mlx_ptr, map->mlx_win);
		ft_settings(map);
		map->count++;
		put_move_count(map);
	}
	return (0);
}
