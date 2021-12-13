/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:59:54 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/12/13 16:24:23 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(n);
	len += ft_putstr(str);
	free (str);
	return (len);
}

int	ft_putunnbr(unsigned int n)
{
	char				*str;
	unsigned int		len;

	len = 0;
	str = ft_strnbr(n);
	len += ft_putstr(str);
	free (str);
	return (len);
}

int	ft_hex(unsigned int n, int oi)
{
	int	len;

	len = 0;
	ft_puthex(n, oi, &len);
	return (len);
}
