/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:33:48 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/12/13 16:24:18 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(char f, va_list args)
{
	int	len;

	len = 0;
	if (f == '%')
		len += ft_putchar('%');
	if (f == 'c')
		len += ft_putchar(va_arg(args, int));
	if (f == 's')
		len += ft_putstr(va_arg(args, char *));
	if (f == 'd' || f == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (f == 'u')
		len += ft_putunnbr(va_arg(args, unsigned int));
	if (f == 'x')
		len += ft_hex(va_arg(args, unsigned int), 0);
	if (f == 'X')
		len += ft_hex(va_arg(args, unsigned int), 1);
	if (f == 'p')
		len += ft_printpointer(va_arg(args, unsigned long));
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;
	char	*pt;
	int		ind;

	ind = 0;
	len = 0;
	va_start (args, string);
	pt = (char *)string;
	while (pt[0] != '\0')
	{
		if (pt[0] == '%')
		{
			len += ft_flags(pt[1], args);
			pt++;
		}
		else
			len += ft_putchar(*pt);
		pt++;
	}
	va_end(args);
	return (len);
}
/*

int	main(void)
{
	ft_printf(" %u \n", -101);
	printf(" %u \n", -101);
	printf("%d\n", ft_printf(" %u \n", -101));
	printf("%d\n", printf(" %u \n", -101));
}*/
