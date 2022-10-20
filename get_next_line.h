/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paime <paime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:09:06 by paime             #+#    #+#             */
/*   Updated: 2021/12/07 11:47:45 by paime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *str, int j);
char	*ft_substr(char const *s, unsigned int start, size_t len, int nb);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_read_file(int fd, char *str);
void	ft_free(char	**str);
int		ft_is_not_n(char *str, int isStarted);

#endif