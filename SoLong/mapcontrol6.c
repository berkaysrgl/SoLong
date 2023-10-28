/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:14 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:43:17 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(int ac, char *av, int fd)
{
	int	i;

	if (ac != 2 || !av)
	{
		write(2, "Error\nInvalid argument\n", 24);
		return (0);
	}
	i = ft_strlen(av);
	i--;
	if (av[i] != 'r' || av[i - 1] != 'e'
		|| av[i - 2] != 'b' || av[i - 3] != '.')
	{
		write(2, "Error\nFile extensiton must be .ber\n", 36);
		return (0);
	}
	if (fd == -1)
	{
		write(2, "Error\nFile descriptor error\n", 29);
		return (0);
	}
	return (1);
}

void	checkvalid(t_mapinfo *map)
{
	if (map->c_c != 0 || map->isvalid != 1 || map->c_e != 0)
		ft_exit(map, 1);
	if (map->column < 3 || map->row < 3)
		ft_exit(map, 2);
}

int	check_ber2(int ac, char *av, int fd)
{
	int	i;
	int	len;

	len = ft_strlen(av);
	i = len -1;
	if (av[i] == 'r' && av[i - 1] == 'e'
		&& av[i - 2] == 'b' && av[i - 3] == '.' && len == 4)
	{
		write(2, "Error\nPLease write file name.\n", 31);
		return (0);
	}
	return (1);
}
