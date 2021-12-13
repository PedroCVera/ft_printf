/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:07:46 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/12/13 16:24:25 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_counter(long int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	n = -n;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	if (n < 0)
		i = 1;
	len = digit_counter(n) + i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	n = n * (((n < 0) * -2) + 1);
	while (len-- != i)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		ind;
	char	*dest;

	ind = 0;
	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (s1[ind] != '\0')
	{
		dest[ind] = s1[ind];
		ind++;
	}
	dest[ind] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s1)
{
	int	ind;

	ind = 0;
	while (s1[ind] != '\0')
		ind++;
	return (ind);
}

char	*ft_strnbr(unsigned int n)
{
	int		len;
	char	*str;

	len = digit_counter(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len-- != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
