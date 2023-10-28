/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:42 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:18:51 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

void	ft_img_increase_me_there(t_mapinfo *mlx)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	mlx->width = 64 * mlx->column;
	mlx->heigth = 64 * mlx->row;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->heigth, "?");
	mlx->vi_front = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/pb.xpm",
			&x, &y);
	mlx->vi_back = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/pf.xpm",
			&x, &y);
	mlx->vi_left = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/pl.xpm",
			&x, &y);
	mlx->vi_right = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/pr.xpm",
			&x, &y);
	mlx->vi_background = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/fl.xpm",
			&x, &y);
	mlx->vi_exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/exit.xpm",
			&x, &y);
	mlx->vi_collect = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/col.xpm",
			&x, &y);
	mlx->vi_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "textures/wall.xpm",
			&x, &y);
}

void	ft_img_put_me_down(t_mapinfo *mlx, char current, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_background,
		x, y);
	if (current == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_wall,
			x, y);
	if (current == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_collect,
			x, y);
	if (current == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_exit, x, y);
	if (current == 'P')
	{
		if (mlx->vi_current == 13)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_back,
				x, y);
		if (mlx->vi_current == 0)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_left,
				x, y);
		if (mlx->vi_current == 1)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_front,
				x, y);
		if (mlx->vi_current == 2)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->vi_right,
				x, y);
	}
}

int	main(int ac, char *argv[])
{
	t_mapinfo	map;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (!check_ber(ac, argv[1], fd))
		return (0);
	if (!check_ber2(ac, argv[1], fd))
		return (0);
	map.mapname = argv[1];
	start(&map);
	ft_img_increase_me_there(&map);
	ft_settings(&map);
	mlx_hook(map.mlx_win, 2, 0, ft_set_win, &map);
	mlx_hook(map.mlx_win, 17, 0, ft_exit, &map);
	mlx_loop(map.mlx_ptr);
	mlx_destroy_window(map.mlx_ptr, map.mlx_ptr);
}
