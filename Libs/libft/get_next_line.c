/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:14:40 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/30 03:31:32 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_advance_and_free(char **chars, char **line, int char_lu)
{
	int		npos;
	int		len;
	char	*str;

	len = 0;
	if (*line)
		len = ft_strlen((*line));
	if (!char_lu && !len)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	npos = ft_strchri(*line, '\n');
	if (npos == -1)
		npos = len;
	str = ft_substr_free(*line, 0, npos + 1, 0);
	ft_bzero(*chars, 10000);
	if (npos < len)
		ft_strlcpy(*chars, (*line) + (npos + 1), len - npos + 1);
	free(*line);
	*line = NULL;
	return (str);
}

int	ft_reading(int fd, char **str, char **line)
{
	int		char_lu;
	char	*temp;

	temp = *str;
	char_lu = read(fd, temp, 1024);
	while (char_lu)
	{
		temp[char_lu] = '\0';
		*line = ft_strjoin_free(*line, temp, 1);
		if (!(*line))
			return (0);
		if (ft_strchri(temp, '\n') != -1)
			break ;
		char_lu = read(fd, temp, 1024);
	}
	free(temp);
	return (char_lu);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	char		*temp;
	static char	chars[4096][10000] = {'\0'};
	int			char_lu;

	if (fd < 0 || fd > 4096 || 1024 < 0)
		return (NULL);
	if (!read(fd, NULL, 0))
	{
		temp = chars[fd];
		str = (char *)malloc(sizeof(char) * (1024 + 1));
		line = ft_strjoin_free(temp, "\0", 666);
		if (!str || !line)
			return (NULL);
		char_lu = ft_reading(fd, &str, &line);
		return (ft_advance_and_free(&temp, &line, char_lu));
	}
	return (NULL);
}
