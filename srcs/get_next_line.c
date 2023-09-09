/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:08:34 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 14:56:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen_nl(char *str, int detect_nl)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c])
		if (str[c++] == '\n' && detect_nl)
			break ;
	return (c);
}

char	*ft_strjoin_gnl(char *dest, char *src)
{
	int		c1;
	int		c2;
	char	*str;
	int		i;

	c1 = ft_strlen_nl(dest, 0);
	c2 = ft_strlen_nl(src, 1);
	str = (char *)malloc(sizeof(char) * (c1 + c2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < c1 && dest)
		str[i] = dest[i];
	i = -1;
	while (++i < c2 && src)
		str[c1 + i] = src[i];
	str[c1 + c2] = '\0';
	if (dest)
		free(dest);
	return (str);
}

static void	update_buffer(char *buffer)
{
	int	i;
	int	len;
	int	max;

	i = -1;
	len = ft_strlen_nl(buffer, 1);
	max = ft_strlen_nl(buffer, 0);
	while (++i + len < max)
		buffer[i] = buffer[i + len];
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
}

static void	makeline(int fd, char buffer[], char **line)
{
	int	bytes;

	bytes = 1;
	while (bytes && !isin(*line, '\n'))
	{
		if (!buffer[0])
			bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			(*line)[0] = '\0';
			return ;
		}
		*line = ft_strjoin_gnl(*line, buffer);
		update_buffer(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	line = ft_strjoin_gnl(NULL, NULL);
	if (!line)
		return (NULL);
	makeline(fd, buffer, &line);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
