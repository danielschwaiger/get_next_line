/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:20 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/06 14:19:24 by dapanciu         ###   ########.fr       */
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
/*-------------END--_FT_PRINTF--------*/


/*----------GNL---------------------------------*/

/*  ssize_t read(int fildes, void *buf, size_t nbyte);  */
char *ft_read(int fd, char *str, char *buffer)
{
	ssize_t	line;

    line = 1;
    while (line > 0)
    {
        line = read(fd, buffer, BUFFER_SIZE);
        if (line == -1)
            free(buffer);
            return (NULL);
        buffer[line] = '\0';
        str = ft_strjoin(str, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    return (str);
}
/*--------------Other functions---------------*/


size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while(s[i] != '\0')   
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
    unsigned int        i;
    char                *res;
    unsigned char       casted_c;

    i = 0;
    casted_c = (unsigned char)c;
    while(s[i])
    {
        if (s[i] == casted_c)
        {
            res = (char *)c;
            return (&res[i]);
        }
    }
    if (s[i] == casted_c)
    {
        res = (char *)c;
        return (&res[i]);
    }
    return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
    int             i;
    int             j;
    char            *ptr;
    unsigned int    size;

    if (!str1)
    {
        str1 = (char *)malloc(1 * sizeof(char));
        str1[0] = '\0';
    }    
    size = ft_strlen(str1) + ft_strlen(str2);
    ptr = (char *)malloc(sizeof(char) * (size + 1));
    if (!ptr)
        return (NULL);
    i = -1;
    j = 0;
    while(str1[++i])
        ptr[i] = str1[i];
    while(str2[j])
        ptr[i++] = str2[j++];
    ptr[size] = '\0';   
    free(str1);
    return (ptr);
}
/*--------------END--GNL------------------------*/