/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:55:16 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 15:37:59 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	occ(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
		if (*(s++) != c)
			if (*s == c || !(*s))
				count++;
	return (count);
}

char	*ft_strndup(const char *s, int len)
{
	char			*obj;

	if (!s)
		return (NULL);
	obj = (char *)malloc(sizeof(char) * len + 1);
	if (!obj)
		return (NULL);
	ft_strlcpy(obj, s, len + 1);
	return (obj);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		flag;
	char	**strs;

	if (!s)
		return (0);
	strs = malloc((occ(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	i = -1;
	j = 0;
	flag = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || !s[i]) && flag >= 0)
		{
			strs[j++] = ft_strndup(&s[flag], i - flag);
			flag = -1;
		}
	}
	strs[j] = 0;
	return (strs);
}
