/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:11:54 by jpicron           #+#    #+#             */
/*   Updated: 2022/08/31 12:55:49 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{	
	char	*dup;
	int		i;

	i = ft_strlen(s);
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *file, char *tmp)
{
	char	*str;
	int		i;
	int		j;

	if (!tmp)
		return (NULL);
	if (!file)
	{
		file = malloc(sizeof(char) * 1);
		if (!file)
			return (NULL);
		file[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(file) + ft_strlen(tmp)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (file[++i])
		str[i] = file[i];
	while (tmp[j])
		str[i++] = tmp[j++];
	str[i] = '\0';
	free(file);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
