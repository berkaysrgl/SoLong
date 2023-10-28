/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:50:58 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 10:04:19 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "getnextline/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_player
{
	void	*vi_front;
	void	*vi_back;
	void	*vi_left;
	void	*vi_right;
	int		current_p_cord;
}	t_player;

typedef struct s_map
{
	void	*vi_wall;
	void	*vi_background;
	void	*vi_collect;
	void	*vi_exit;
}	t_map;

typedef struct s_mapinfo
{
	void	*vi_front;
	void	*vi_back;
	void	*vi_left;
	void	*vi_right;
	int		current_p_cord;
	char	**map;
	char	**tmpmap;
	char	*mapname;
	void	*mlx_win;
	void	*mlx_ptr;
	int		heigth;
	int		width;
	int		move_c;
	int		row;
	int		column;
	int		isvalid;
	int		fd;
	int		vi_current;
	int		count;
	int		exit;
	int		px;
	int		py;
	int		c_p;
	int		c_e;
	int		c_c;
	int		x;
	int		y;
	int		current_c;
	void	*vi_wall;
	void	*vi_background;
	void	*vi_collect;
	void	*vi_exit;
}	t_mapinfo;

char	*ft_itoa(int n);
void	put_move_count(t_mapinfo *map);
void	wallcheck(t_mapinfo *map);
void	start(t_mapinfo *map);
void	structinit(t_mapinfo *map);
void	getmap(t_mapinfo *map);
void	openmap(t_mapinfo *map);
void	allocatemap(t_mapinfo *array);
void	getrow(t_mapinfo *map);
void	getcolumn(t_mapinfo *map);
void	start(t_mapinfo *map);
int		ft_exit(t_mapinfo *map, int errno);
void	freemap(t_mapinfo *map);
void	wallcheck(t_mapinfo *wall);
void	checkchar(t_mapinfo *map);
void	validchar(t_mapinfo *map);
void	structinit2(t_mapinfo *map);
void	ft_validmap_check(t_mapinfo *arg, int x, int y);
void	getplayer(t_mapinfo *map);
void	gettmp(t_mapinfo *map);
char	*ft_strdup2(char *a);
void	checkvalid(t_mapinfo *map);
void	ft_img_increase_me_there(t_mapinfo *mlx);
void	ft_img_put_me_down(t_mapinfo *mlx, char current, int x, int y);
void	ft_settings(t_mapinfo *arg);
void	ft_rplc(t_mapinfo *map, int x, int y, int k);
int		ft_set_win(int keycode, t_mapinfo *map);
int		ft_check_wall(t_mapinfo *arg, int k);
int		ft_check_ext(t_mapinfo *arg, int k);
int		ft_l_strlen(char *str);
void	check_diff(t_mapinfo *arg);
void	if_enter(t_mapinfo *map);
int		check_ber(int ac, char *av, int fd);
void	control1(t_mapinfo *map);
int		ft_strnstr(const char *name, const char *f);
int		check_ber2(int ac, char *av, int fd);
#endif