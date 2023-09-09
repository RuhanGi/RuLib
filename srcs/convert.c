/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:48:53 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 14:56:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *(str++) - '0';
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}

static int	numlength(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0 && ++len)
		n /= 10;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = numlength(n);
	num = (char *)malloc(sizeof(char) * len + 1);
	if (!num)
		return (NULL);
	num[len--] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		num[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
