/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:47:57 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 14:56:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *) s)[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloced;

	if (size && count > INT_MAX / size)
		return (NULL);
	alloced = (void *) malloc(count * size);
	if (!alloced)
		return (alloced);
	ft_bzero(alloced, count * size);
	return (alloced);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	isin(const char *buffer, char c)
{
	while (*buffer)
		if (*(buffer++) == c)
			return (1);
	return (0);
}
