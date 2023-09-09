/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:59:36 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 14:56:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;

	if ((!haystack && len <= 0) || !(*needle))
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i + ft_strlen(needle) <= len))
		if (ft_strncmp(&haystack[i++], needle, ft_strlen(needle)) == 0)
			return ((char *)&haystack[i - 1]);
	return (0);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	i;

	if (dstsize == 0 || dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	i = 0;
	while (i < dstsize - c - 1 && src[i])
	{
		dst[c + i] = src[i];
		i++; 
	}
	dst[c + i] = '\0';
	return (c + ft_strlen(src));
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*a;
	unsigned int	c;

	if (!s)
		return (NULL);
	c = ft_strlen(s);
	a = (char *)malloc(sizeof(char) * c + 1);
	if (!a)
		return (NULL);
	i = -1;
	while (++i < c)
		a[i] = f(i, s[i]);
	a[c] = '\0';
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		i;
	char	*a;

	if (!s1)
		return (NULL);
	while (isin(set, *s1))
		s1++;
	c = ft_strlen(s1);
	while (c > 0 && isin(set, s1[c - 1]))
		c--;
	a = (char *) malloc(sizeof(char) * c + 1);
	if (!a)
		return (NULL);
	i = -1;
	while (++i < c)
		a[i] = s1[i];
	a[c] = '\0';
	return (a);
}
