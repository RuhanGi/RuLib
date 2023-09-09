/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:24:11 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/09 12:31:46 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
		write(fd, s++, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
		return (write(fd, "-", 1) + ft_putnbr_fd(-n, fd));
	if (n > 9)
		return (ft_putnbr_fd(n / 10, fd) + write(fd, &"0123456789"[n % 10], 1));
	return (write(fd, &"0123456789"[n], 1));
}
