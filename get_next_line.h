/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:53:54 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/21 17:27:22 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*newline(char *ost);
char	*newost(char *ost);
char	*reading(int fd, char *ost);
char	*ft_sstrjoin(char *s1, char *s2);
int		ft_sstrlen(char *s);
int		ncount(char *s);
char	*ft_sstrchr(char *str, char c);
#endif
