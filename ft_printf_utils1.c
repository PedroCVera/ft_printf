/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:09:59 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/12/13 16:24:16 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, int oi, int *len)
{
	if (n >= 16)
		ft_puthex(n / 16, oi, len);
	if (oi == 0)
		*len += ft_putchar("0123456789abcdef"[n % 16]);
	if (oi == 1)
		*len += ft_putchar("0123456789ABCDEF"[n % 16]);
}

int	hexcount(unsigned int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n > 16)
	{
		n /= 16;
		c++;
	}
	c++;
	return (c);
}

int	ft_printpointer(unsigned long pnt)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	if (pnt == 0)
		len += ft_putchar('0');
	else
		ft_putptr(pnt, &len);
	return (len);
}

void	ft_putptr(unsigned long ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
		*len += ft_putchar("0123456789abcdef"[ptr % 16]);
}
