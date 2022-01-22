/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:54:48 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/21 17:27:14 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading(int fd, char *ost)
{
	int			wasread;
	char		buf[BUFFER_SIZE + 1];

	wasread = 1;
	while (wasread > 0 && !ft_sstrchr(ost, '\n'))
	{
		wasread = read(fd, buf, BUFFER_SIZE);
		if (wasread < 0)
			return (NULL);
		buf[wasread] = '\0';
		if (!ost)
		{
			ost = malloc(1);
			if (!ost)
				return (NULL);
			ost[0] = '\0';
		}
		ost = ft_sstrjoin(ost, buf);
	}
	return (ost);
}

char	*newline(char *ost)
{
	char	*line;
	int		i;

	i = 0;
	if (!*ost)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (ncount(ost) + 1));
	if (!line)
		return (NULL);
	while (ost[i] != '\n' && ost[i] != '\0')
	{
		line[i] = ost[i];
		i++;
	}
	if (ost[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*newost(char *ost)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ost[i] != '\n' && ost[i] != '\0')
		i++;
	if (!ost[i])
	{
		free(ost);
		return (NULL);
	}	
	line = (char *)malloc(sizeof(char) * (ft_sstrlen(ost) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (ost[i] != '\0')
		line[j++] = ost[i++];
	line[j] = '\0';
	free(ost);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*ost;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ost = reading(fd, ost);
	if (!ost)
		return (NULL);
	line = newline(ost);
	ost = newost(ost);
	return (line);
}
