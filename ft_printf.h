/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:35:01 by pcoimbra          #+#    #+#             */
/*   Updated: 2021/12/13 16:21:02 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <stdarg.h>

int			ft_putchar(char c);
int			ft_printf(const char *string, ...);
int			ft_flags(char f, va_list args);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s1);
int			ft_putunnbr(unsigned int n);
char		*ft_strnbr(unsigned int n);
int			ft_hex(unsigned int n, int oi);
void		ft_puthex(unsigned int n, int oi, int *len);
int			ft_printpointer(unsigned long pnt);
void		ft_putptr(unsigned long ptr, int *len);

#endif
