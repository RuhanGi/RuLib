/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:24:06 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 12:31:36 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putstr(char *str)
{
	while (str && *str)
		write(1, str++, 1);
}

void	ft_putendl(char *str)
{
	if (!str)
		return ;
	ft_putstr(str);
	write(1, "\n", 1);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
		return (write(1, "-", 1) + ft_putnbr(-n));
	if (n > 9)
		return (ft_putnbr(n / 10) + write(1, &"0123456789"[n % 10], 1));
	return (write(1, &"0123456789"[n], 1));
}
