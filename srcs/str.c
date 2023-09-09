/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:54:54 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 14:56:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s && s[c])
		c++;
	return (c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = -1;
	while ((size_t)++i < n)
		if (s1[i] != s2[i] || !(s1[i]) || !(s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*obj;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	obj = (char *)malloc(sizeof(char) * len + 1);
	if (!obj)
		return (NULL);
	ft_strcpy(obj, s);
	return (obj);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		c1;

	if (!s1 || !s2)
		return (NULL);
	c1 = ft_strlen(s1);
	a = (char *)malloc(sizeof(char) * (c1 + ft_strlen(s2)) + 1);
	if (!a)
		return (NULL);
	ft_strcpy(a, s1);
	ft_strcpy(&a[c1], s2);
	return (a);
}
