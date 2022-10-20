/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paime <paime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:17:14 by paime             #+#    #+#             */
/*   Updated: 2021/11/19 11:27:40 by paime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*mem;
	char			*memstock;
	unsigned int	i;

	i = 0;
	mem = NULL;
	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	memstock = (char *)mem;
	while (i < (size * nmemb))
	{
		memstock[i] = '\0';
		++i;
	}
	return (mem);
}

int	ft_strlen(const char *str, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		while (str[i])
			i++;
		return (i);
	}
	else if (j == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] && str[i] == '\n')
			i++;
		return (i);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len, int nb)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	newstr = NULL;
	if (!s || len == 0)
		return (0);
	if (len > (size_t)ft_strlen(s, 0))
		len = ft_strlen(s, 0);
	newstr = ft_calloc((len + 1), sizeof(char));
	if (!newstr)
		return (0);
	if (start < (unsigned int)ft_strlen((char *)s, 0))
	{
		while (i < (start + len) && s[i])
			newstr[j++] = s[i++];
	}
	if (nb == 1)
		free((void *)s);
	newstr[j] = 0;
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1, 0);
		len2 = ft_strlen(s2, 0);
		str = ft_calloc((len1 + len2 + 1), sizeof(char));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
			str[len1++] = s2[i];
		str[len1] = '\0';
		free((void *)s1);
		return (str);
	}
	return (NULL);
}

int	ft_read_file(int fd, char *str)
{
	int	ret;

	ret = read(fd, str, BUFFER_SIZE);
	while (ret > 0)
	{
		str[ret] = 0;
		return (1);
	}
	return (0);
}
