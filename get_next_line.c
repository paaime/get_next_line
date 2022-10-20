/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:57:30 by paime             #+#    #+#             */
/*   Updated: 2022/10/20 21:56:36 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(char	**str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int	ft_is_not_n(char *str, int isStarted)
{
	int	i;

	i = 0;
	if (!isStarted)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		str[BUFFER_SIZE + 1];
	char		*line_copy;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, str, 0) < 0)
		return (NULL);
	if (!line)
		line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (ft_is_not_n(line, i++) && ft_read_file(fd, str))
		line = ft_strjoin(line, str);
	if (ft_strlen(line, 1) > 0)
		line_copy = ft_substr(line, 0, ft_strlen(line, 1), 0);
	else
	{
		ft_free(&line);
		return (NULL);
	}
	line = ft_substr(line, ft_strlen(line, 1), ft_strlen(line, 0), 1);
	return (line_copy);
}

int main(void)
{
	int	fd;

	fd = open("42", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}