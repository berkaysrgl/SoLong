/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:48:05 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/12 09:02:59 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_diff(t_mapinfo *arg)
{
	int		i;
	int		j;
	int		len;
	char	t;

	i = 0;
	len = arg->column;
	while (i < arg->row)
	{
		j = 0;
		while (j < len)
		{
			t = arg->map[i][j];
			if (t != 'C' && t != 'P' && t != 'E' && t != '1' && t != '0')
			{
				write(1, "This map doesnt have correct characters.", 41);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	ft_l_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}
