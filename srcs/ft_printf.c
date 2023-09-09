/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:34:25 by aoweis            #+#    #+#             */
/*   Updated: 2023/09/09 14:56:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_fputstr(char *str)
{
	if (!str)
		return (ft_fputstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putu(unsigned long n, char c, int b)
{
	if (n >= (unsigned long) b)
		return (ft_putu(n / b, c, b) + ft_putu(n % b, c, b));
	if (c == 'x' || c == 'p')
		return (write(1, &"0123456789abcdef"[n], 1));
	return (write(1, &"0123456789ABCDEF"[n], 1));
}

int	handletype(va_list ap, const char *str)
{
	if (*str == '%')
		return (ft_putchar('%'));
	if (*str == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (*str == 's')
		return (ft_fputstr(va_arg(ap, char *)));
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (*str == 'u')
		return (ft_putu(va_arg(ap, unsigned int), 'u', 10));
	if (*str == 'x' || *str == 'X')
		return (ft_putu(va_arg(ap, unsigned int), *str, 16));
	if (*str == 'p')
		return (ft_fputstr("0x") + ft_putu(va_arg(ap, unsigned long), 'p', 16));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
			len += handletype(ap, ++str);
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (len);
}
