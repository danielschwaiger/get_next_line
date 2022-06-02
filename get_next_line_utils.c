/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:20 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/01 12:49:43 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*------ft_printf_functions----------*/

int ft_putchar(char c)
{
	int dest;

	dest = 0;
	dest += write(1, &c, 1);
	return (dest);
}

int ft_putstr(char *s)
{
	int val;

	if(!s)
		return (ft_putstr("(null)"));
	val = 0;
	while(*s)
		val += ft_putchar(*s++);
	return (val);
}

int ft_print_hexa(unsigned long int nb, char c)
{
	int res;

	res = 0;

	if(c == 'x' || c == 'p')
	{
		if (nb >= 16)
			res += (ft_print_hexa(nb / 16, c));
		res += ft_putchar("0123456789abcdef"[nb % 16]);
	}
	else if (c == 'X')
	{
		if(nb >= 16)
			res += ft_print_hexa(nb / 16, c);
		res += ft_putchar("0123456789ABCDEF"[nb % 16]);
	}
	return (res);
}

int ft_putnbr(int nb)
{
	int dest;

	dest = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		dest += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		dest += ft_putnbr(nb / 10);
	nb = nb % 10;
	if (nb < 10)
		dest += ft_putchar(nb + '0');
	return (dest);
}

int ft_putnbr_u(unsigned int nb)
{
	int dest;

	dest = 0;
	if (nb >= 10)
		dest += ft_putnbr_u(nb / 10);
	nb = nb % 10;
	if (nb < 10)
		dest += ft_putchar(nb + '0');
	return (dest);
}

int	ft_read_types(va_list ap, char x)
{
	int	i;

	i = 0;
	if (x == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (x == '%')
		i += ft_putchar('%');
	else if (x == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (x == 'd' || x == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (x == 'p')
		i += ft_putstr("0x") + ft_print_hexa(va_arg(ap, unsigned long int), x);
	else if (x == 'x' || x == 'X')
		i += ft_print_hexa(va_arg(ap, unsigned int), x);
	else
		if (x == 'u')
			i += ft_putnbr_u(va_arg(ap, unsigned int));
	return (i);
}

int	ft_printf(char const *frmt, ...)
{
	va_list				pd;
	int					i;

	i = 0;
	va_start(pd, frmt);
	while (*frmt != '\0')
	{
		if (*frmt == '%')
			i += ft_read_types(pd, *++frmt);
 		else
			i += ft_putchar(*frmt);
		frmt++;
	}
	va_end(pd);
	return (i);
}
/*-------------END--_FT_PRINF--------*/


/*----------GNL---------------------------------*/

/*  ssize_t read(int fildes, void *buf, size_t nbyte);  */
char *ft_read(int fd, char *str, char *buffer)
{
	ssize_t	nr_bytes;

}

/*--------------END--GNL------------------------*/