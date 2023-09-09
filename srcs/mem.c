/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:14:32 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 14:56:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = -1;
	while (++i < n)
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return ((void *)&(((unsigned char *) s)[i]));
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = -1;
	while (++i < n)
		if (((unsigned char *) s1)[i] != ((unsigned char *) s2)[i])
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (0);
	i = 0;
	while (i++ < n)
		*((char *) dst++) = *((char *) src++);
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	if (!src && !dst)
		return (0);
	i = 0;
	a = (char *) dst;
	b = (char *) src;
	if (a > b)
		while (n-- > 0)
			a[n] = b[n];
	else
		while (i++ < n)
			*(a++) = *(b++);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
		((unsigned char *) b)[i++] = (unsigned char) c;
	return (b);
}
