/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarigul <yangidenmuzaffer@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:17:53 by bsarigul          #+#    #+#             */
/*   Updated: 2023/09/07 23:17:54 by bsarigul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	*ft_memcpy(void	*dst, const void *src, size_t n);
char	*ft_strdup(char	*str1);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*get_buff(int fd, char *str);
char	*get_returnline(char *str);
char	*dlt_line(char *str);
#endif
