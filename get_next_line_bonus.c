/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:12:09 by jpicron           #+#    #+#             */
/*   Updated: 2022/08/31 12:56:01 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_llenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_new_file(char *str)
{
	int		llenght;
	int		i;
	char	*new;

	i = 0;
	llenght = ft_llenght(str);
	if (!str[llenght])
	{
		free(str);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(str) - llenght + 1));
	if (!new)
		return (NULL);
	llenght++;
	while (str[llenght])
	{
		new[i] = str[llenght];
		i++;
		llenght++;
	}
	new[i] = '\0';
	free (str);
	return (new);
}

char	*ft_read_str(int fd, char *str)
{
	int		nbr_char;
	char	*tmp;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	nbr_char = 1;
	while (!ft_strchr(str, '\n') && nbr_char != 0)
	{
		nbr_char = read(fd, tmp, BUFFER_SIZE);
		if (nbr_char < 0)
		{
			free (tmp);
			return (NULL);
		}
		tmp[nbr_char] = '\0';
		str = ft_strjoin(str, tmp);
		if (!str)
			return (NULL);
	}
	free(tmp);
	return (str);
}

char	*ft_get_line(char *str)
{
	int		llenght;
	int		i;
	char	*tmp;

	i = 0;
	if (!str[i])
		return (NULL);
	llenght = ft_llenght(str);
	tmp = malloc(sizeof(char) * llenght + 2);
	if (!tmp)
		return (NULL);
	while (i <= llenght)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_str(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	res = ft_get_line(str[fd]);
	str[fd] = ft_new_file(str[fd]);
	return (res);
}
