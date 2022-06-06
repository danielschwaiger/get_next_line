/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:23 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/06 14:07:19 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdarg.h>
# include <unistd.h>

/*------ft_printf---functions-----------------*/

/*------------------Specifier-----------------*/
int	ft_printf(char const *frmt, ...);
int	ft_read_types(va_list ap, char c);
/*--------------Other functions---------------*/
int	ft_print_hexa(unsigned long int nb, char c);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);


/*-----------------end_ft_printf---------------*/

/*----------GNL---------------------------------*/

char *get_next_line(int fd);
char *ft_read(int fd, char *str, char *buffer);

/*--------------Other functions---------------*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *str1, char *str2);

/*--------------END--GNL------------------------*/
#endif