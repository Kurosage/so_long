/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaren <rmaren@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:54:39 by rmaren            #+#    #+#             */
/*   Updated: 2022/01/21 17:26:58 by rmaren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_sstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_sstrchr(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_sstrjoin(char *s1, char *s2)
{
	char	*pp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	pp = (char *)malloc(sizeof(char) * (ft_sstrlen(s1) + ft_sstrlen(s2) + 1));
	if (!pp)
		return (NULL);
	while (s1[i] != '\0')
	{
		pp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		pp[i++] = s2[j++];
	pp[i] = '\0';
	free(s1);
	return (pp);
}

int	ncount(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (i + 1);
}
